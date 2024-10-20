#include<iostream>
#include<vector>
#include<map>
using namespace std;
void keyboard(char side, string text){
    map<char,vector<char>> m;
    string answer;
    m['q']={' ','w'};
    m['a']={' ','s'};
    m['z']={' ','x'};
    m['w']={'q','e'};
    m['s']={'a','d'};
    m['x']={'z','c'};
    m['e']={'w','r'};
    m['d']={'s','f'};
    m['c']={'x','v'};
    m['r']={'e','t'};
    m['f']={'d','g'};
    m['v']={'c','b'};
    m['t']={'r','y'};
    m['g']={'f','h'};
    m['b']={'v','n'};
    m['y']={'t','u'};
    m['h']={'g','j'};
    m['n']={'b','m'};
    m['u']={'y','i'};
    m['j']={'h','k'};
    m['m']={'n',','};
    m['i']={'u','o'};
    m['k']={'j','l'};
    m[',']={'m','.'};
    m['o']={'i','p'};
    m['l']={'k',';'};
    m['.']={',','/'};
    m['p']={'o',' '};
    m[';']={'l',' '};
    m['/']={'.',' '};
    int select;
    if (side = 'L') select = 1;
    else select = 0;
    for (int i=0; i<text.size(); i++){
        answer.push_back(m[text[i]][select]);
    }
    for (int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    cout << endl; 
}
int main() {
    char side;
    string text;
    cin >> side ; 
    cin >> text ;
    keyboard(side,text);
}