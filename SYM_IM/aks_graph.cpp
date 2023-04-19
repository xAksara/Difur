

extern unsigned int N;

using std::cout, std::cin, std::endl, std::string;

struct vertex {
    unsigned int num = 0;
    unsigned int color = 0;
    bool visited = 0;
};

void write_graph(vertex** graph) {
    std::ofstream file;
    file.open("files/obraz.txt");
    for(int i = 1; i <= N; i++) {
        file << graph[i][0].num << ": ";
        for(int j = 1; graph[i][j].num != -1 && j <= N; j++) {
            file << graph[i][j].num << " ";
        }
        file << endl;
    }
    file.close();
}

std::vector<unsigned int> road;
std::set<unsigned int> returnable;

vertex* vert = new vertex[N+1];

void dfs(vertex** graph, int now) {
    vert[now].color = 1;
    road.push_back(now);
    int neig;
    if (vert[now].visited == 0) vert[now].visited = 1;

    for(int i = 1; (neig = graph[now][i].num) != -1; i++) {
        if (vert[neig].color == 0) {
            dfs(graph, neig);
        }
        else if (vert[neig].color == 1) {
            cout << endl << "cycle: " << neig;
            for(auto v = road.end() - 1; *v != neig; v--) {
                returnable.insert(*v);
                cout << " <- " << *v;
            }
            cout << endl;
        }
    }
    vert[now].color = 2;
    road.pop_back();
}

void print_returnable() {
    cout << "возвр" << endl;
    for (auto i : returnable) {
        cout << i << ", ";
    }
    cout << endl;
}

void clear_color() {
    for (int i = 1; i <= N; i++) {
        vert[i].color = 0;
    }
}