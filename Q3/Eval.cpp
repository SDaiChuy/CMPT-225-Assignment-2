/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Steven Dai Chuy
 * Date: October 5, 2022
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;



int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    // Pretty printer coding demo.  Please remove before coding
    while (t.tt != eof) {
        if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
            cout << t;
        } else if (t.tt == pltok || t.tt == mitok || 
                   t.tt == asttok || t.tt == slashtok) {
            cout << ' ' << t << ' ';
        }

        t = S.getnext();
    }

    cout << endl;
    // End pretty printer coding demo.

    while(t.tt != eof || opstack.isEmpty() != true){
        if(t.tt == integer){
            numstack.push(t);
        }
        else if(t.tt == lptok){
            opstack.push(t);
        }
        
        else if(t.tt == rptok){
            Token top = opstack.peek();
            if(top.tt == lptok){
                cout << "working" << endl;
                opstack.pop();
            }
            else{
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                
                Token result = S.getnext() 
            }
        }

    }

    return 0;
}

