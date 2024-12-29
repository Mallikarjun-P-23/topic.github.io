#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

struct Product {
    std::string name;
    int quantity;
    double price;
};

struct Edge {
    int product1_index;
    int product2_index;
    double weight;
};

int findSet(int i, std::vector<int>& parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i], parent);
}

void unionSets(int i, int j, std::vector<int>& parent, std::vector<int>& rank) {
    int rootI = findSet(i, parent);
    int rootJ = findSet(j, parent);
    if (rootI != rootJ) {
        if (rank[rootI] > rank[rootJ])
            parent[rootJ] = rootI;
        else if (rank[rootI] < rank[rootJ])
            parent[rootI] = rootJ;
        else {
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
    }
}

void kruskal(std::vector<Product>& products) {
    int n = products.size();
    std::vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double weight = std::fabs(products[i].price - products[j].price);
            edges.push_back({i, j, weight});
        }
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.weight < e2.weight;
    });

    std::vector<int> parent(n);
    std::vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    std::cout << "Minimum Spanning Tree (MST) edges based on price differences:\n";
    for (const auto& edge : edges) {
        int root1 = findSet(edge.product1_index, parent);
        int root2 = findSet(edge.product2_index, parent);

        if (root1 != root2) {
            std::cout << "Product " << products[edge.product1_index].name << " and Product "
                      << products[edge.product2_index].name << " with price difference: "
                      << edge.weight << "\n";
            unionSets(root1, root2, parent, rank);
        }
    }
}

void readInventoryFromFile(const std::string &filename, std::vector<Product> &inventory) {
    std::ifstream file(filename);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            Product product;
            std::istringstream ss(line);
            std::getline(ss, product.name, ',');
            ss >> product.quantity;
            ss.ignore();
            ss >> product.price;
            inventory.push_back(product);
        }
        file.close();
    } else {
        std::cerr << "Could not open file: " << filename << "\n";
    }
}

int main() {
    std::vector<Product> inventory;
    
    // Replace with the correct path to your inventory.txt file
    readInventoryFromFile("Inventory.txt", inventory);

    
    kruskal(inventory);
    
    return 0;
}
