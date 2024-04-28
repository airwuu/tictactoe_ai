#ifndef STRONGAI_H
#define STRONGAI_H
#include <iostream>
#include <vector>
#include "GameState.h"


struct Node{
    GameState data;
    std::vector<Node*> children;
    int height;
    std::vector<int> imoves;
    std::vector<int> jmoves;
    Node(GameState board){
        data = board;
    }
};

void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

Node* populate(Node* root, int height = 0){
    root->height = height;
    if(!(root->data.hasWon(0)||root->data.hasWon(1))){
        for (int i = 0; i < root->data.size; i++){
            for (int j = 0; j < root->data.size; j++){
                if (root->data.grid[i][j] == -1){
                    GameState newData = root->data;
                    newData.play(i,j);
                    Node* newNode = new Node(newData);
                    newNode->imoves.push_back(i);
                    newNode->jmoves.push_back(j);
                    addChild(root, populate(newNode, height+1));
                }
            }
        }
    }
    return root;
}

// void printWinningBoards(Node* root, int playerNum = 0) {
//     if (root == nullptr) {
//         return;
//     }
//     if (root->children.empty()) {
//         if(root->data.hasWon(playerNum)){
//             std::cout << "Height: "<< root->height << " \n";
//             std::cout << root->data << " \n";
//         } 
//     } 
//     else {
//         for (Node* child : root->children) {
//             printWinningBoards(child, playerNum);
//         }
//     }
// }

Node* findMinHeight(Node* root, int playerNum = 0) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // If the current node is a leaf node, return it
    if (root->children.empty()) {
        return root;
    }

    Node* minLeaf = nullptr;
    for (Node* child : root->children) {
        Node* leaf = findMinHeight(child); 
        if (leaf != nullptr && (minLeaf == nullptr || leaf->height < minLeaf->height)) {
            if(leaf->data.hasWon(playerNum)){
                minLeaf = leaf;
            }
        }
    }
    
    return minLeaf;
}
Vec aiMove(Node* root, int playerNum = 0) {
    Node* poggers = findMinHeight(root, playerNum);
    Vec thing = Vec(poggers->imoves[0], poggers->jmoves[0]);
    return thing;
}

#endif

