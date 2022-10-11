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

    /*
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
    */

    while(t.tt != eof || opstack.isEmpty() != true){
        if(t.tt == integer){
            cout << "Working" << endl;
            numstack.push(t);
            cout << "t: " << t << endl;
            t = S.getnext();
            cout << "t: " << t << endl;
        }
        else if(t.tt == lptok){
            opstack.push(t);
            cout << "t: " << t << endl;
            t = S.getnext();
            cout << "t: " << t << endl;
        }
        
        else if(t.tt == rptok){
            Token top = opstack.peek();
            cout << "top: " << top << endl;
            if(top.tt == lptok){
                cout << "working" << endl;
                opstack.pop();
            }
            else{
                Token result;
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                
                cout << "x.val: " << x.val << endl; 
                numstack.push(result);
                cout << "t: " << t << endl;
                t = S.getnext();
                cout << "t: " << t << endl;
            }
        }
        else if(t.tt == pltok || t.tt == mitok || t.tt == eof ){
            cout << "Working1 " << endl;
            TokenType top = t.tt;
            cout << "working2 " << endl;
            cout << "top: " << top << endl;
            if(opstack.isEmpty() == false && top == pltok || top == mitok || top == asttok || top == slashtok ){
                Token result;
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                numstack.push(result);
                cout << "t: " << t << endl;
                t = S.getnext();
                cout << "t: " << t << endl;
            }
            else{
                opstack.push(t);
                cout << "t: " << t << endl;
                t = S.getnext();
                cout << "t: " << t << endl;
            }
        }
        else if(t.tt == asttok || t.tt == slashtok){
            Token top = opstack.peek();
            cout << "top: " << top << endl;
            if(opstack.isEmpty() == false && (top.tt == asttok || top.tt == slashtok)){
                Token result;
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();

                numstack.push(result);
            }
            else{
                opstack.push(t);
                cout << "t: " << t << endl;
                t = S.getnext();
                cout << "t: " << t << endl;
            }
        }

    }

    return 0;
}

