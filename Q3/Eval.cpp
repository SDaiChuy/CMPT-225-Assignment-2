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

    while(t.tt != eof || opstack.isEmpty() != true){
        if(t.tt == integer){
            cout << "pushing: " << t.val << " onto the numstack" << endl;
            numstack.push(t);
            t = S.getnext();
        }

        else if(t.tt == lptok){
            cout << "Pushing: " <<  t.text << " onto the opstack" << endl;
            opstack.push(t);
            t = S.getnext();
        }
        
        else if(t.tt == rptok){
            if(opstack.peek().tt == lptok){
                opstack.pop();
                t = S.getnext();
            }
            else{
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                Token result;
                result.tt = integer;

                if(op.tt == pltok){
                    result.val = y.val + x.val;
                }
                else if(op.tt == mitok){
                    result.val = y.val - x.val;
                }
                else if(op.tt == asttok){
                    result.val = y.val * x.val;
                }
                else if(op.tt == slashtok){
                    result.val = y.val / x.val;
                }
                cout << "Pushing result: " << result.val << " onto the numstack" << endl;
                numstack.push(result);

            }
        }
        else if(t.tt == pltok || t.tt == mitok || t.tt == eof){
            if(opstack.isEmpty() == false && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok )){
                Token result;
                result.tt = integer;

                Token x = numstack.pop();

                Token y = numstack.pop();

                Token op = opstack.pop();

                if(op.tt == pltok){
                    result.val = y.val + x.val;
                }
                else if(op.tt == mitok){
                    result.val = y.val - x.val;
                }
                else if(op.tt == asttok){
                    result.val = y.val * x.val;
                }
                else if(op.tt == slashtok){
                    result.val = y.val / x.val;
                }

                cout << "pushing  " << result << " onto the numstack" << endl;;
                numstack.push(result);
            }
            else{
                cout << "Pushing " << t.text << " onto the opstack" << endl;
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if(t.tt == asttok || t.tt == slashtok){
            if(opstack.isEmpty() == false && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){
                Token result;
                result.tt = integer;
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                if(op.tt == asttok){
                    result.val = y.val * x.val;
                }
                else if(op.tt == slashtok){
                    result.val = y.val / x.val;
                }
                cout << "pushing " << result.val << " onto the numstack" << endl;
                numstack.push(result);
            }
            else{
                cout << "Pushing " << t.text << " onto the opstack" << endl;
                opstack.push(t);
                t = S.getnext();
        
            }
        }   
        else{
            cout << "Error" << endl;
        }

    }

    cout << "result: " << numstack.pop().val << endl;

    return 0;
}

