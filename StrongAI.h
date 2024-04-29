#ifndef STRONGAI_H
#define STRONGAI_H
#include <iostream>
#include <vector>
#include "GameState.h"

// Node struct
struct Node{
    // Node data
    GameState data;
    // Node children
    std::vector<Node*> children;
    // Node height
    int height;
    // Node moves
    std::vector<int> imoves;
    std::vector<int> jmoves;
    // Node constructor
    Node(GameState board){
        data = board;
    }
};

// addChild function
void addChild(Node* parent, Node* child) {
    // Puts child node to vector in parent Node
    parent->children.push_back(child);
}

// Populate Function
Node* populate(Node* root, int height = 0){
    // Set root height
    root->height = height;

    if(!(root->data.hasWon(0)||root->data.hasWon(1))){ // if game is not over
        // Loop through grid
        for (int i = 0; i < root->data.size; i++){
            for (int j = 0; j < root->data.size; j++){
                // if cell is empty
                if (root->data.grid[i][j] == -1){
                    // Create new gamestate
                    GameState newData = root->data;
                    // Play move
                    newData.play(i,j);
                    // Create new node
                    Node* newNode = new Node(newData);
                    // Add moves to node
                    newNode->imoves.push_back(i);
                    newNode->jmoves.push_back(j);
                    // Recursively populate the tree
                    addChild(root, populate(newNode, height+1));
                }
            }
        }
    }
    // return
    return root;
}

// NOT NEEDED...

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

// function to find the minimum height of a winning board (shortest path)
Node* findMinHeight(Node* root, int playerNum) {
    // If the root is null, return null
    if (root == nullptr) {
        return nullptr;
    }
    
    // If the current node is a leaf node, return it
    if (root->children.empty()) {
        return root;
    }

    // Initialize the minimum leaf node to null
    Node* minLeaf = nullptr;
    // Loop through the children of the current node
    for (Node* child : root->children) {
        // Recursively find the minimum height of a winning board
        Node* leaf = findMinHeight(child, playerNum);       
        // If the leaf node is not null and the height of the leaf node is less than the height of the minimum leaf node
        if (leaf != nullptr && (minLeaf == nullptr || leaf->height <= minLeaf->height)) {
            // Update the minimum leaf node
            if ((leaf->data.hasWon(0)||leaf->data.hasWon(1))) {
                minLeaf = leaf;
            }
            // If the leaf node has won, update the minimum leaf node
            if (leaf->data.hasWon(playerNum)) {
                minLeaf = leaf;
            } 
        }
    }
    // return
    return minLeaf;
}

// function to find the best move for the AI
Vec aiMove(Node* root, int playerNum = 1) {
    // Find the minimum height of a winning board
    Node* poggers = findMinHeight(root, playerNum);
    // Return the first move of the winning board
    Vec thing = Vec(poggers->imoves[0], poggers->jmoves[0]);
    // return
    return thing;
}

#endif

