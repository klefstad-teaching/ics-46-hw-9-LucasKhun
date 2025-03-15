#include "./dijkstras.h"

void run_dijkstras(vector<string> input_files, int start){
    for(string f : input_files){
        Graph G;
        ifstream file(f);
        file >> G;

        vector<int> previous(G.numVertices);
        vector<int> result = dijkstra_shortest_path(G, start, previous);

        for(int i=0; i<G.numVertices; ++i)
            print_path(extract_shortest_path(result, previous, i), result[i]);
        file.close();
    }
}

int main(){
    vector<string> input_files = {
                                    "/home/lkhun/46/ics-46-hw-9-LucasKhun/src/small.txt",
                                    "/home/lkhun/46/ics-46-hw-9-LucasKhun/src/medium.txt",
                                    "/home/lkhun/46/ics-46-hw-9-LucasKhun/src/large.txt",
                                    "/home/lkhun/46/ics-46-hw-9-LucasKhun/src/largest.txt"
                                };
    run_dijkstras(input_files, 0);
    return 0;
}