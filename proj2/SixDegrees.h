/*
 * Proj2: SixDegrees of Collabortation
 * cs15
 * SixDegrees.h
 * Caroline Chin 
 * 12/8/2021
 * Implementation of SixDegrees Interface. Includes helper functions for 
 * command loop, contains the graph used in simulation.
 */



#ifndef _SIXDEGREES_H_
#define _SIXDEGREES_H_

#include "Artist.h"
#include "CollabGraph.h"

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class SixDegrees {
    public:
        SixDegrees(ifstream &artists);
        ~SixDegrees();
        void run_command_loop(istream &input, ostream &output);
    private:
        CollabGraph graph;
        vector <Artist> artist_list;
        void BFS(Artist artist1, Artist artist2, ostream &output);
        void DFS(Artist artist1, Artist artist2, ostream &output);
        void DFS_helper(Artist artist1, Artist artist2);
        //bool is_artist(string name, ostream &output);
        Artist get_artist(string name, ostream &output);
        void print_path(stack<Artist> path, ostream& output, 
            Artist one, Artist two);
        void call_not(istream &input, ostream &output, 
            Artist artist1, Artist artist2);
        void NOT(vector<Artist> exclude, ostream &output, 
            Artist artist1, Artist artist2);
};

#endif