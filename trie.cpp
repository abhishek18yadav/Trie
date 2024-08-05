#include<bits/stdc++.h>
using namespace std;


class node{
        public:
        char data;
        bool isTerminal;
        unordered_map<char , node*>children;
        node(char data){
            this->data = data;
            isTerminal = false;
        }
    };

class Trie{
    public:
    node* root;
    Trie(){
        root = new node('\0');
    }
    void insert(string word){
        node* temp = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(temp->children.find(ch)!= temp->children.end()){
                temp= temp->children[ch];
            }else{
                node* n= new node(ch);
                temp->children[ch]=n;
                temp = temp->children[ch];
            }
        }
        temp->isTerminal= true;
    }
    bool search(string word){
        node* temp = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(temp->children.count(ch)){
                temp= temp->children[ch];
            }else{
                return false;
            }
        }
        return temp->isTerminal;
    }
    bool startswith(string word){
        node* temp = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(temp->children.count(ch)){
                temp= temp->children[ch];
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Trie t ;
    t.insert("abhi");
    t.insert("atul");
    t.insert("shai");
    cout<<t.search("yadav");

    return 0;
}
    
    