
#include<iostream>
 #include<stack>
 
using namespace std;

int cert(char c){
     switch(c){
               case ' ': return 7;
               case '=': return 6;
               case ')': return 5;
               case '(': return 4;
               case '/': return 3;
               case '*': return 2;
               case '-': return 1;
               case '+': return 0;
               default : return 8;
               }
     }

int getd(char c){
     switch(c){
               case '0': return 0;
               case '1': return 1;
               case '2': return 2;
               case '3': return 3;
               case '4': return 4;
               case '5': return 5;
               case '6': return 6;
               case '7': return 7;
               case '8': return 8;
               case '9': return 9;
               }
     }

int calc(int a,int b,int i){
     switch(i){
               case 0: return a+b;
               case 1: return a-b;
               case 2: return a*b;
               case 3: return a/b;
               }
     }

int p1211(char *hbl,string s){
     int f[7][7]={1,1,0,0,0,1,1,
                 1,1,0,0,0,1,1,
                 1,1,1,1,0,1,1,
                 1,1,1,1,0,1,1,
                 0,0,0,0,0,2,3,
                 1,1,1,1,3,1,1,
                 0,0,0,0,0,3,2};
     int cnum;
     cin >> cnum;
     getline(cin,s);
     while(cnum--){
     getline(cin,s);
                   int len = s.length();
                   
                   s[len] = '=';
                   ++len;
                   
                   stack<int> opf;
                   stack<int> opd;
                   opf.push(6);
                   int in = 0;
                   while(in < len){
                             int si = cert(s[in]);
                             if(si == 8){
                                   int tmp1 = getd(s[in]);
                                   if(in>0 && cert(s[in-1])==8){int tmp2 = opd.top()*10+tmp1;opd.pop();opd.push(tmp2);}
                                   else opd.push(tmp1);
                                   ++in;
                                               }
                             else if (si != 7){
                                 switch(f[opf.top()][si]){
                                                           case 0: opf.push(si);++in;break;
                                                           case 1: {
                                                               int b = opd.top();opd.pop();
                                                               int a = opd.top();opd.pop();
                                                               int c = opf.top();opf.pop();
                                                               opd.push(calc(a,b,c));
                                                               break;
                                                               }
                                                           case 2: opf.pop();++in;break;
                                                           case 3: return 0;
                                                 }
                                 }
                             else ++in;
                             }
                   cout << opd.top()<<endl; 
                   }
 }

int main(){
     char hbl[51];
     string str; 
     p1211(hbl,str);
     return 0;
     }


