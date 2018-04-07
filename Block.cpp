// #include "Blockchain.h"
// #include <string>
// #include <vector>
// #include <iostream>
//
// using namespace std;
//
// Blockchain::Blockchain() {
//     chain.push_back(createGenesisBlock());
// }
//
// Block Blockchain::createGenesisBlock() {
//     Block b(0, "01/01/2018", "Genesis Block");
//     return b;
// }
// 
// Block Blockchain::getLatestBlock() {
//     return chain[chain.size() - 1];
// }
//
// void Blockchain::addBlock(Block newBlock) {
//     Block latestBlock = getLatestBlock();
//     newBlock.previousHash = latestBlock.getHash();
//     newBlock.setHash(newBlock.calculateHash());
//     chain.push_back(newBlock);
// }
//
// void Blockchain::printBlockchain() {
//     for(int i = 0; i < chain.size(); i++) {
//         cout << "Hash for Block " << i + 1 << " ";
//         chain[i].printInfo();
//         cout << endl;
//     }
// }
