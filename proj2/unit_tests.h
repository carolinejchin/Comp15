/*
 * Proj2: Six Degrees
 * cs15
 * unit_tests.h
 * Caroline Chin 
 * 10/13/2021
 * Unit testing for CollabGraph
 */

#include <cassert>
#include <iostream>
#include "CollabGraph.h"
#include "Artist.h"
#include "SixDegrees.h"
#include <vector>
using namespace std;

/*    populate_test
 *    Purpose: tests populate graph with varying sizes of graphs
 *    Parameters: none 
 *    Returns: none
 */
void populate_test() {
    CollabGraph graph;

    Artist h ("h");
    Artist j ("j");
    Artist k ("k");
    Artist l ("l");
    Artist g ("g");

    h.add_song("A");
    j.add_song("A");
    h.add_song("B");
    k.add_song("B");
    g.add_song("B");
    k.add_song("C");
    l.add_song("C");

    vector<Artist> artists;
    //empty vector
    //graph.populate_graph(artists);
    artists.push_back(h);
    //one artist
    //graph.populate_graph(artists);
    artists.push_back(j);
    artists.push_back(k);
    artists.push_back(g);
    artists.push_back(l);

    graph.populate_graph(artists);
    cerr << "print" << endl;
    graph.print_graph(cerr);
}

/*    get_vertex_test
 *    Purpose: tests get_vertex_neighbors with artists of different
 *      numbers of neighbors
 *    Parameters: none 
 *    Returns: none
 */
void get_vertex_test() {
    CollabGraph graph;

    Artist h ("h");
    Artist j ("j");
    Artist k ("k");
    Artist l ("l");
    Artist g ("g");

    h.add_song("A");
    j.add_song("A");
    h.add_song("B");
    k.add_song("B");
    g.add_song("B");
    k.add_song("C");
    l.add_song("C");
    
    vector<Artist> artists;
    //empty vector
    artists.push_back(h);
    //one artist
    artists.push_back(j);
    artists.push_back(k);
    artists.push_back(g);
    artists.push_back(l);

    graph.populate_graph(artists);
    graph.get_vertex_neighbors(j);
    graph.get_vertex_neighbors(l);
    vector<Artist> neighbors = graph.get_vertex_neighbors(j);
}

/*    report_test
 *    Purpose: manually sets predecessors to test report path on 
 *      connected artists
 *    Parameters: none 
 *    Returns: none
 */
void report_test() {
    CollabGraph graph;
    
    Artist h ("h");
    Artist j ("j");
    Artist k ("k");
    Artist l ("l");
    Artist g ("g");

    l.add_song("A");
    l.add_song("B");
    g.add_song("A");
    k.add_song("B");
    k.add_song("C");
    j.add_song("C");
    
    vector<Artist> artists;
    artists.push_back(h);
    artists.push_back(j);
    artists.push_back(k);
    artists.push_back(g);
    artists.push_back(l);

    graph.populate_graph(artists);

    graph.set_predecessor(l, g);
    graph.report_path(g, l);
    graph.set_predecessor(k, l);
    graph.report_path(g, k);
    graph.set_predecessor(j, k);
    graph.report_path(g, j);
}
   