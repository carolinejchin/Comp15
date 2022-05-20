/*
 * Proj2: SixDegrees of Collaboration
 * cs15
 * SixDegrees.cpp
 * Caroline Chin 
 * 12/8/2021
 * Implementation of SixDegrees class. Reads in artist file, runs command loop 
 * and includes functions to assist in executing commands.
 */

#include "SixDegrees.h"
#include "CollabGraph.h"
#include "Artist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*    Default Constructor 
 *    Purpose: Reads in the artist file and populates the graph
 *      also creates list of artists
 *    Parameters: file with artists and songs
 *    Returns: none
 */
SixDegrees::SixDegrees(ifstream &artists) {
    string line;  
    string star;      
    while (not artists.eof()) {
        Artist enter;
        getline(artists, line); // artist name
        enter.set_name(line);
        getline(artists, line);
        while (line != "*") {
            enter.add_song(line);
            getline(artists, line);
        }
        artist_list.push_back(enter);
    }
    graph.populate_graph(artist_list);
}

/*    Destructor 
 *    Purpose: destructs
 *    Parameters: none 
 *    Returns: none
 */
SixDegrees::~SixDegrees() {

}

/*    run_command_loop
 *    Purpose: takes in commands and calls the proper helper
 *      functions
 *    Parameters: input and output file
 *    Returns: none
 */
void SixDegrees::run_command_loop(istream &input, ostream &output) {
    string command, firstArtist, secondArtist;
    bool done = false;
    while (done == false and not input.eof()) {
        input >> command;
        if (command == "quit") {
            done = true;
        }
        else if (command == "print") {
            graph.print_graph(output);
        }
        else if (command == "bfs" or command == "dfs" or command == "not"){
            input.ignore();
            getline(input, firstArtist);
            getline(input, secondArtist);
            
            Artist one = get_artist(firstArtist, output);
            Artist two = get_artist(secondArtist, output);
            if (command == "bfs") {
                BFS(one, two, output);
            }
            else if(command == "dfs") {
                DFS(one, two, output);
            }
            else if(command == "not") {
                call_not(input, output, one, two);
            }
        }
        else {
            output << command << " is not a command. Please try again." << endl;
        }
    }
}

/*    get_artist 
 *    Purpose: finds artist in artist list with given name
 *    Parameters: string name of artist, output file
 *    Returns: artist with correcsponding name 
 */
Artist SixDegrees::get_artist(string name, ostream &output) {
    for (int i = 0; i < artist_list.size(); i++) {
        if(name == artist_list[i].get_name()) {
            return artist_list[i];
        }
    }
    output <<  "\"" << name  << "\"" 
        << " was not found in the dataset :(" << endl;
    exit(EXIT_FAILURE);
}

/*    BFS
 *    Purpose: Takes in two artists and conducts a bfs search
 *      between the two by setting predecessors
 *    Parameters: two artists, source and dest, output file
 *    Returns: none
 */
void SixDegrees::BFS(Artist artist1, Artist artist2, ostream &output) {
    graph.clear_metadata();

    queue<Artist> queue;
    graph.mark_vertex(artist1);
    queue.push(artist1);

    while (queue.size() != 0) {
        Artist current = queue.front();
        queue.pop();
        vector<Artist> neighbors = graph.get_vertex_neighbors(current);
        for (int i = 0; i < neighbors.size(); i++) {
            if(graph.is_marked(neighbors.at(i)) == false) {
                graph.mark_vertex(neighbors.at(i));
                graph.set_predecessor(neighbors.at(i), current);
                queue.push(neighbors.at(i));
            }
        }
    }
    print_path(graph.report_path(artist1, artist2), output, artist1, artist2);
}

/*    DFS
 *    Purpose: Conducts DFS search between two given artists by calling
 *      dfs helper
 *    Parameters: two artists, source and dest, output file
 *    Returns: none
 */
void SixDegrees::DFS(Artist artist1, Artist artist2, ostream &output) {
    graph.clear_metadata();

    DFS_helper(artist1, artist2);
    print_path(graph.report_path(artist1, artist2), output, artist1, artist2);
}

/*    DFS_helper
 *    Purpose: recursively conducts dfs search between two artists
 *    Parameters: two artists, source and dest
 *    Returns: none
 */
void SixDegrees::DFS_helper(Artist artist1, Artist artist2) {
    if (artist1 == artist2) {
        return;
    }
    else {
        graph.mark_vertex(artist1);
        vector<Artist> neighbors = graph.get_vertex_neighbors(artist1);
        for (int i = 0; i < neighbors.size(); i++) {
            if (graph.is_marked(neighbors[i]) == false) {
                graph.set_predecessor(neighbors[i], artist1);
                DFS_helper(neighbors[i], artist2);
            }
        }
    }
}

/*    call_not
 *    Purpose: takes in extra artists for exclude list and calls NOT
 *      function
 *    Parameters: input file, output file, atrists source and dest 
 *    Returns: none
 */
void SixDegrees::call_not(istream &input, ostream &output, 
    Artist artist1, Artist artist2) {
    
    string line;
    vector<Artist> list;
    getline(input, line);
    while(line != "*") {
        Artist temp = get_artist(line, output);
        list.push_back(temp);
        getline(input,line);
    }
    NOT(list, output, artist1, artist2);
}

/*    NOT
 *    Purpose: conducts BFS search on the two artists, and
 *      takes care of excluded artists by avoiding their paths
 *    Parameters: vector of excluded artists, output file, artists,
 *      source and dest
 *    Returns: none
 */
void SixDegrees::NOT(vector<Artist> exclude, ostream &output, 
    Artist artist1, Artist artist2) {
    
    graph.clear_metadata();

    queue<Artist> queue;
    graph.mark_vertex(artist1);
    queue.push(artist1);
    bool excluded = false;

    while (queue.size() != 0) {
        Artist current = queue.front();
        queue.pop();
        vector<Artist> neighbors = graph.get_vertex_neighbors(current);
        for (int i = 0; i < neighbors.size(); i++) {
            for (int j = 0; j < exclude.size(); j++) {
                if (neighbors[i] == exclude[j]) {
                    excluded = true;
                }
            }
            if(graph.is_marked(neighbors.at(i)) == false and excluded == false) {
                graph.mark_vertex(neighbors.at(i));
                graph.set_predecessor(neighbors.at(i), current);
                queue.push(neighbors.at(i));
            }
            excluded = false;
        }
    }
    print_path(graph.report_path(artist1, artist2), output, artist1, artist2);
}

/*    print_path
 *    Purpose: prints the path between two artists
 *    Parameters: stack of the path, output file, two artists,
 *      source and dest
 *    Returns: none
 */
void SixDegrees::print_path(stack<Artist> path, ostream& output, 
    Artist one, Artist two) {
    Artist first;
    Artist second;
    if (one == two or path.size() == 0) {
        output << "A path does not exist between \"" << one << "\" and \"" << two << "\"." << endl;
        return;
    }
    path.pop();
    while (!path.empty()) {
        first = path.top();
        second = graph.get_predecessor(first);
        output << "\"" << second.get_name() << "\" collaborated with \"" <<
        first.get_name() << "\" in \"" << first.get_collaboration(second) <<
        "\"." << endl;
        path.pop();
    }
    output << "***" << endl;
}

