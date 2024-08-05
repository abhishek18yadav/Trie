class node{
    constructor(data){
        this.data = data;
        this.isterminal=false;
        this.children = {};
        // mapping  of  char --->  node address
    }
};
class trie{
    constructor(){
        this.root = new node(null);
    }
    insert(word){
        let curr = this.root;

        for(let i=0; i<word.length; i++){
            let char = word[i];
            if(curr.children[char]){
                curr= curr.children[char]; 
            }
            else{
                let n = new node(char);
                curr.children[char]= n;
                curr = curr.children[char];
            }
        }
        curr.isterminal=true;
    }
  
    search(word){
        let curr = this.root;
        for(let i=0;i < word.length; i++){
            let char = word[i];
            if(curr.children[char]){
                curr=curr.children[char];
            }else{
                return false;
            }
        }
        return curr.isterminal;
    }

}
var t = new trie();
t.insert("abhi");
t.insert("abh");
console.log(t.search("abhi"));