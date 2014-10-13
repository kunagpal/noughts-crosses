#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int a[10][10]={},l[100],b[10][10],i,j,n,k,f1,f2,s1,s2,c,r,v; LARGE_INTEGER x,y,z; char ch,s[10],na[2][10],c1,c2; HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); time_t ti=time(0); float p[10];
void m()
{ system("cls");  v=0;
cout<<"\n\n\n\n\n\n\n\n\n\t  Press 1 for a directed graph, 2 for an undirected graph.\n\n\n\t\tPress any other key to return to the Main Menu: "; ch=getch(); 
 if(ch!='1'&&ch!='2') return;
  system("cls");  
  cout<<"\n\n  Enter the order: ";  cin>>n; if(!n) return;
  cout<<"\n  Enter "<<n*n<<" elements:\n"; 
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  { cin>>a[i][j];  b[i][j]=a[i][j]; if(a[i][j]>v) v=a[i][j];}
  QueryPerformanceCounter(&x); 
  for(i=0;i<n;i++)
 {  j=-1; st: while((j<n)&&(!a[i][++j])); s1=j; f1=f2=0;  s2=i;
  for(k=0;k<n;k++) if(a[i][k]) if(a[i][k]<a[i][s1]) {s1=k; f1=1; break;}
  for(k=0;k<n;k++) if(a[k][j]) if(a[k][j]<a[s2][j]) {s2=k; f2=1; break;}
  if(f1&&f2) {if(a[i][j]<v) {v=a[i][j]; r=i; c=j;} a[i][j]=0; if(ch=='2') a[j][i]=0; }
  if(s1<n) goto st;
 }
  k=0;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  if(a[i][j]) k++;
  if(k<n-1) { a[r][c]=v; if(ch=='2') a[c][r]=v;} 
  QueryPerformanceCounter(&y); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  cout<<"\n\n\tMST:\n";
  for(i=0;i<n;i++)
 { cout<<endl<<'\t'; 
  for(j=0;j<n;j++)
 { if(a[i][j]) cout<<a[i][j];
  else { SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<char(236); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);}
  cout<<' ';
 }
 }
cout<<"\n\n\tMinimization was completed in "; SetConsoleTextAttribute(h,FOREGROUND_GREEN); cout<<float((y.QuadPart-x.QuadPart))/z.QuadPart; 
SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); cout<<" s\n\n\tPress any key to continue....."; getch();}
void tr(int i=0) {if(i<k) {if(i>0) { if(!(i%2)) cout<<char(192); else cout<<char(196); cout<<l[i]; } tr(2*i+1); cout<<endl; for(j=0;j<i;j++) cout<<"  "; cout<<' '; tr(2*(i+1));}}
void g()
{do
{ system("cls"); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<char(4); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 cout<<"\n\n\n\t\t\t\t  Graph Menu:\n\n"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 cout<<"\n\t\t\t\t1.Graph to MST\n\n\n\n\t\t\t    2.MST to Binary tree\n\n\n\n\t\t\t3.Shortest, Longest path calculation\n\n\n\n\t\t\t    Esc.Back to Main Menu\n\n\n"; 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(4);  SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\n\nEnter choice: "; ch=getch();
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 switch(ch)
  { case '1': m(); break;
    case '2': system("cls"); k=0; 
	          for(i=0;i<n;i++) 
              for(j=0;j<n;j++) 
              if(i<j) {if(a[i][j]) l[k++]=a[i][j]; }
              cout<<"The binary equivalent of the MST is:\n"<<l[0]; tr(); cout<<"\n\nPress any key to continue..."; getch();
			  break; 
    case '3': system("cls"); cout<<"Enter the serial numbers of the vertices involved: "; cin>>r>>c;
              QueryPerformanceCounter(&x);
			  for(k=0;k<n;k++)
              for(i=0;i<n;i++)
			  for(j=0;j<n;j++)
              a[i][j]=(b[i][j]<(b[i][k]+b[k][j]))?b[i][j]:(b[i][k]+b[k][j]);
	          QueryPerformanceCounter(&y);
			  cout<<"\n\nShortest path length: (Calculated in "; SetConsoleTextAttribute(h,FOREGROUND_GREEN);  cout<<((float(y.QuadPart-x.QuadPart)/z.QuadPart)*1000000)/1000; 
			  SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<" ms) "; 
			  if (!a[r-1][c-1]) cout<<char(236);
              else cout<<a[r-1][c-1];
	          QueryPerformanceCounter(&x);
			  for(k=0;k<n;k++)
              for(i=0;i<n;i++)
			  for(j=0;j<n;j++)
              a[i][j]=(b[i][j]>(b[i][k]+b[k][j]))?b[i][j]:(b[i][k]+b[k][j]);
	          QueryPerformanceCounter(&y);
			  cout<<"\n\nLongest path length: (Calculated in "; SetConsoleTextAttribute(h,FOREGROUND_GREEN);  cout<<((float(y.QuadPart-x.QuadPart)/z.QuadPart)*1000000)/1000; 
			  SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<" ms) ";  
			  if (!a[r-1][c-1]) cout<<char(236);
              else cout<<a[r-1][c-1];      
	          cout<<"\n\nPress any key to continue..."; getch();
	          break;
	case 27: break;
  }
}while(ch!=27);
}
void pr(int i=0) {if(i<n) {cout<<l[i]<<' '; pr(2*i+1); pr(2*(i+1));}}
void po(int i=0) {if(i<n) {po(2*i+1); po(2*(i+1)); cout<<l[i]<<' ';}}
void in(int i=0) {if(i<n) {in(2*i+1); cout<<l[i]<<' '; in(2*(i+1));}}
void e()
{ system("cls"); i=0; 
   cout<<" Enter expression to be evaluated: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
   cin>>p[i]>>s[i];
   while(s[i]!='=')
   {    i++;
      cin>>p[i]>>s[i];
      switch(s[i-1])
      { case '+': p[i]+=p[i-1]; break;
        case '-': p[i]=p[i-1]-l[i]; break;
        case '*': 
        case 'x': p[i]*=p[i-1]*p[i]; break;
        case '/': p[i]=p[i-1]/p[i]; break;
        case '^': p[i]=pow(p[i-1],p[i]); break;
        default: break;
      }
   }       
 cout<<p[i]<<"\nPress any key to continue...."; getch();
}
void exp()
{ system("cls"); na[0][0]='('; cout<<"Enter the expression: "; 
SetConsoleTextAttribute(h,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); cin>>s;
 s[strlen(s)]=')'; j=i=k=0;
  while(s[i])
  { switch(s[i])
    { case '(': na[0][k++]=s[i]; break;
	  case ')': while(na[0][k]!='(') {na[1][j++]=na[0][k--];} k--; break;
	  case '+': 
	  case '-': while(na[0][k]!='(') {na[1][j++]=na[0][k--];} na[0][++k]=s[i]; break;
	  case '%': 
	  case '&': 
	  case '|': while((na[0][k]!='(')&&(na[0][k]!='+')&&(na[0][k]!='-')) {na[1][j++]=na[0][k--];} na[0][++k]=s[i]; break;
	  case '*': 
	  case '/': while((na[0][k]!='\(')&&(na[0][k]!='+')&&(na[0][k]!='-')&&(na[0][k]!='%')&&(na[0][k]!='&')&&(na[0][k]!='|')) {na[1][j++]=na[0][k--];} na[0][++k]=s[i]; break;
	  case '^': while((na[0][k]!='(')&&(na[0][k]!='+')&&(na[0][k]!='-')&&(na[0][k]!='%')&&(na[0][k]!='&')&&(na[0][k]!='|')&&(na[0][k]!='*')&&(na[0][k]!='/')) {na[1][j++]=na[0][k--];} na[0][++k]=s[i]; break;
	  default:  na[1][j++]=s[i];
	}
   i++;
  }
 cout<<"Postfix: "; SetConsoleTextAttribute(h,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
 for(i=0;i<j;i++) cout<<na[1][i];
 SetConsoleTextAttribute(h,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN); cout<<"\nPress any key to continue...."; getch();
}
void t()
{ do
{ system("cls"); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<char(18); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 cout<<"\n\n\n\t\t\t\t  Tree Menu:\n\n"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 cout<<"\n\t\t\t       1.Tree formation\n\n\n\t\t\t\t 2.Traversals\n\n\n\t\t\t3.Expression evaluation using trees\n\n\n\t\t\t     4.Infix to postfix\n\n\n\t\t\t     Esc.Back to Main Menu\n\n\n"; 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(18);  SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\n\nEnter choice: "; ch=getch(); 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 switch(ch)
  { case '1':system("cls"); cout<<"Enter the no. of elements: "; cin>>k; cout<<"Enter "<<k<<" elements:";
	         for(i=0;i<k;i++) cin>>l[i]; cout<<"\t\tThe tree is:\n\n"; cout<<l[0]; tr(); cout<<"Press any key to continue...."; getch(); 
	         break;
    case '2': system("cls"); cout<<"\nEnter the no. of elements: "; cin>>n; cout<<"\nEnter "<<n<<" elements:";
	          for(i=0;i<n;i++) cin>>l[i]; SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\nPostorder: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  po(); 
 SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\n\nPreorder: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  pr();
SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\n\nInorder: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); in(); 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"Press any key to continue...."; getch(); break;
    case '3': e(); break;
    case '4': exp(); break;
    case 27: break;
  }
}while(ch!=27);
}
void t1()
{ srand(time(0)); k=1; s1=0; s2=0; system("cls");
  d: i=0,j=0; char f[][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};  int w1[8]={},w2[8]={};
 do
{ system("cls");
cout<<"\t\t\tRound "<<k<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<"X"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); 
cout<<": CPU1: "<<s1<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<"O"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<": CPU2: "<<s2<<endl; 
for(f1=0;f1<3;f1++) 
{ cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl<<'\t'<<char(179); 
  for(f2=0;f2<3;f2++) 
{ if(f[f1][f2]=='O') {SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<'O';} else if(f[f1][f2]=='X') {SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<'X';} else cout<<' '; 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);cout<<char(179);}
}
cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl; 
if(j>=5) 
  { f2=-1; 
   for(f1=0;f1<8;f1++) 
   { if(!w1[f1]&&w2[f1]) 
	   switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='X')) f2=0; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='X')) f2=0; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[2][2]==f[1][2])&&(f[1][2]=='X')) f2=0; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='X')) f2=0; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][2]=='X')) f2=0; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='X')) f2=0; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='X')) f2=0; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='X')) f2=0; break;
	   }
	   else if(!w2[f1]&&w1[f1])
	   switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='O')) f2=1; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='O')) f2=1; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[2][2]==f[1][2])&&(f[0][2]=='O')) f2=1; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='O')) f2=1; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][0]=='O')) f2=1; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='O')) f2=1; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='O')) f2=1; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='O')) f2=1; break;
	   }
	   if(f2!=-1) 
	 {  cout<<"\nCPU"<<(f2%2)+1<<" wins!"; 
	   if(f2) ++s2; 
	   else ++s1;
	   break;
	 }
   }  
  if(f2!=-1) break;
  }
if(j++>=9) {cout<<"Round draw!\n"; break;}
 cout<<"CPU"<<(i%2)+1<<"'s turn."; b: r=rand()%4+1; c=rand()%4+1;
  if(f[r-1][c-1]!=' ') goto b;
  Sleep(900);
  f[r-1][c-1]=(i%2)?'O':'X';  
  switch(r)
 { case 1:
  { if(i%2) w1[3]=1; else w2[3]=1;  
   if(c==1) if(i%2) {w1[0]=1; w1[7]=1;} else {w2[0]=1; w2[7]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[6]=1; } else {w2[2]=1; w2[6]=1; }
  } break;
   case 2:
   { if(i%2) w1[4]=1; else w2[4]=1;
    if(c==1) if(i%2) w1[0]=1; else w2[0]=1; 
    else if(c==2) if(i%2) {w1[1]=1; w1[6]=1; w1[7]=1;} else {w2[1]=1; w2[6]=1; w2[7]=1;}
    else if(c==3) if(i%2) w1[2]=1; else w2[2]=1; 
  } break;
  case 3:
  { if(i%2) w1[5]=1; else w2[5]=1;
    if(c==1)  if(i%2) {w1[0]=1; w1[6]=1;} else {w2[0]=1; w2[6]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[7]=1;} else {w2[2]=1; w2[7]=1;}
  } break;
  }
++i;
}while(j<10);
 cout<<"\nPress y to simulate again, press any other key to exit: "; c1=getch(); 
 if((c1=='y')||(c1=='Y')) {k++; goto d;}
 else cout<<endl;
 if(s1>s2) cout<<"\nCPU1 wins "<<s1<<'-'<<s2;
 else if(s2>s1) cout<<"\nCPU2 wins "<<s2<<'-'<<s1;
 else cout<<"\nDraw!";
 getch();
}
void t2()
{ k=1; s1=0; s2=0; system("cls");
  cout<<"Player ("; SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<'X'; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); 
  cout<<"), enter your name: "; cin>>na[0]; 
  d: i=0,j=0; char f[][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};  int w1[8]={},w2[8]={};
 do
{ system("cls");
cout<<"\t\t\tRound "<<k<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<"X: ";  SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); 
cout<<na[0]<<'-'<<s1<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<"O: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<"CPU -"<<s2<<endl; 
for(f1=0;f1<3;f1++) 
{ cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl<<'\t'<<char(179); 
  for(f2=0;f2<3;f2++) 
{ if(f[f1][f2]=='O') {SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<'O';} else if(f[f1][f2]=='X') {SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<'X';} else cout<<' '; 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);cout<<char(179);}
}
cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl; 
if(j>=9) {cout<<"Round draw!\n"; break;}
if(j>=5) 
{ f2=-1; 
  for(f1=0;f1<8;f1++) 
  { if(!w1[f1]&&w2[f1]) 
    switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='X')) f2=0; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='X')) f2=0; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[1][2]==f[2][2])&&(f[0][2]=='X')) f2=0; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='X')) f2=0; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][0]=='X')) f2=0; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='X')) f2=0; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='X')) f2=0; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='X')) f2=0; break;
	   }
	   else if(!w2[f1]&&w1[f1])
	   switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='O')) f2=1; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='O')) f2=1; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[2][2]==f[1][2])&&(f[0][2]=='O')) f2=1; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='O')) f2=1; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][0]=='O')) f2=1; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='O')) f2=1; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='O')) f2=1; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='O')) f2=1; break;
	   }
	   if(f2!=-1) 
	 {  if(f2) {cout<<"\nCPU wins!"; ++s2; } 
	   else { cout<<"You win!"; ++s1; }
	   break;
	 }
 }  
}
cout<<na[0]<<", it's your turn. Enter the row and column of the box. (Press Esc to Quit)"; b: c1=getch(); 
if(c1==27) { cout<<'\n'<<na[(i+1)%2]<<" wins!\n"; if(i%2) ++s1; else ++s2; goto e;  } if(isdigit(c1)) cout<<c1; else goto b; r=int(c1)-48; cin>>c; 
  if(f[r-1][c-1]!=' ') {cout<<"\nPlease choose a non empty box! "; cout<<'\7';  goto b;}
f[r-1][c-1]='X'; 
  switch(r)
 { case 1:
  { if(i%2) w1[3]=1; else w2[3]=1;  
   if(c==1) if(i%2) {w1[0]=1; w1[7]=1;} else {w2[0]=1; w2[7]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[6]=1; } else {w2[2]=1; w2[6]=1; }
  } break;
   case 2:
   { if(i%2) w1[4]=1; else w2[4]=1;
    if(c==1) if(i%2) w1[0]=1;  else w2[0]=1; 
    else if(c==2) if(i%2) {w1[1]=1; w1[6]=1; w1[7]=1;} else {w2[1]=1; w2[6]=1; w2[7]=1;}
    else if(c==3) if(i%2) w1[2]=1; else w2[2]=1; 
  } break;
  case 3:
  { if(i%2) w1[5]=1; else w2[5]=1;
    if(c==1)  if(i%2) {w1[0]=1; w1[6]=1;} else {w2[0]=1; w2[6]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[7]=1;} else {w2[2]=1; w2[7]=1;}
  } break;
  } 
++j; f2=0;
for(i=0;i<8;i++)
{ if(!w1[i]&&w2[i])
 switch(i)
 { case 0: if ((f[0][0]==f[1][0])&&(f[1][0]=='X')&&(f[2][0]==' ')) {f[2][0]='O'; f2=w1[0]=w1[5]=w1[6]=1;}
           else if ((f[1][0]==f[2][0])&&(f[1][0]=='X')&&(f[0][0]==' ')) {f[0][0]='O'; f2=w1[0]=w1[3]=w1[7]=1;}
           else if ((f[0][0]==f[2][0])&&(f[0][0]=='X')&&(f[1][0]==' ')) {f[1][0]='O'; f2=w1[0]=w1[4]=1;}
		   break;
   case 1: if ((f[0][1]==f[1][1])&&(f[0][1]=='X')&&(f[2][1]==' ')) {f[2][1]='O'; f2=w1[5]=w1[1]=1;}
           else if ((f[0][1]==f[2][1])&&(f[0][1]=='X')&&(f[1][1]==' ')) {f[1][1]='O'; f2=w1[1]=w1[6]=w1[7]=w1[4]=1;}
           else if ((f[2][1]==f[1][1])&&(f[1][1]=='X')&&(f[0][1]==' ')) {f[0][1]='O'; f2=w1[1]=w1[3]=1;}
            break;
   case 2: if ((f[0][2]==f[1][2])&&(f[1][2]=='X')&&(f[2][2]==' ')) {f[2][2]='O'; f2=w1[2]=w1[5]=w1[7]=1;}
           else if ((f[0][2]==f[2][2])&&(f[2][2]=='X')&&(f[1][2]==' ')) {f[1][2]='O'; f2=w1[2]=w1[4]=1;}
           else if ((f[1][2]==f[2][2])&&(f[2][2]=='X')&&(f[0][2]==' ')) {f[0][2]='O'; f2=w1[2]=w1[3]=w1[6]=1;}
            break;
   case 3: if ((f[0][0]==f[0][1])&&(f[0][0]=='X')&&(f[0][2]==' ')) {f[0][2]='O'; f2=w1[2]=w1[3]=w1[6]=1;}
           else if ((f[0][0]==f[0][2])&&(f[0][0]=='X')&&(f[0][1]==' ')) {f[0][1]='O'; f2=w1[3]=w1[1]=1;}
           else if ((f[0][1]==f[0][2])&&(f[0][1]=='X')&&(f[0][0]==' ')) {f[0][0]='O'; f2=w1[0]=w1[3]=w1[7]=1;}
            break;
   case 4: if ((f[1][0]==f[1][1])&&(f[1][0]=='X')&&(f[1][2]==' ')) {f[1][2]='O'; f2=w1[2]=w1[4]=1;}
           else if ((f[1][0]==f[1][2])&&(f[1][0]=='X')&&(f[1][1]==' ')) {f[1][1]='O'; f2=w1[1]=w1[6]=w1[7]=w1[4]=1;}
           else if ((f[1][1]==f[1][2])&&(f[1][1]=='X')&&(f[1][0]==' ')) {f[1][0]='O'; f2=w1[0]=w1[4]=1;}
            break;
   case 5: if ((f[2][0]==f[2][1])&&(f[2][0]=='X')&&(f[2][2]==' ')) {f[2][2]='O'; f2=w1[2]=w1[5]=w1[7]=1;}
           else if ((f[2][0]==f[2][2])&&(f[2][0]=='X')&&(f[2][1]==' ')) {f[2][1]='O'; f2=w1[1]=w1[5]=1;}
           else if ((f[2][1]==f[2][2])&&(f[2][1]=='X')&&(f[2][0]==' ')) {f[2][0]='O'; f2=w1[0]=w1[5]=w1[6]=1;}
            break;
   case 6: if ((f[0][2]==f[1][1])&&(f[1][1]=='X')&&(f[2][0]==' ')) {f[2][0]='O'; f2=w1[0]=w1[5]=w1[6]=1;}
           else if ((f[1][1]==f[2][0])&&(f[1][1]=='X')&&(f[0][2]==' ')) {f[0][2]='O'; f2=w1[2]=w1[3]=w1[6]=1;}
           else if ((f[0][2]==f[2][0])&&(f[2][0]=='X')&&(f[1][1]==' ')) {f[1][1]='O'; f2=w1[1]=w1[6]=w1[7]=w1[4]=1;}
            break;
   case 7: if ((f[0][0]==f[1][1])&&(f[1][1]=='X')&&(f[2][2]==' ')) {f[2][2]='O'; f2=w1[2]=w1[5]=w1[7]=1;}
           else if ((f[1][1]==f[2][2])&&(f[1][1]=='X')&&(f[0][0]==' ')) {f[0][0]='O'; f2=w1[0]=w1[3]=w1[7]=1;}
           else if ((f[0][0]==f[2][2])&&(f[2][2]=='X')&&(f[1][0]==' ')) {f[1][1]='O'; f2=w1[7]=w1[4]=w1[6]=w1[1]=1;}
            break;
 }
  if(f2) break; 
} 
if(!f2)
{ if(f[1][1]==' ') {f[1][1]='O'; f2=w1[1]=w1[4]=w1[6]=w1[7]=1;}
 else if(f[2][2]==' ')  {f[2][2]='O'; f2=w1[2]=w1[5]=w1[7]=1;}
 else if(f[0][2]==' ')  {f[0][2]='O'; f2=w1[2]=w1[3]=w1[6]=1;}
 else if(f[2][0]==' ')  {f[0][2]='O'; f2=w1[0]=w1[5]=w1[6]=1;}
 else if(f[0][0]==' ')  {f[0][2]='O'; f2=w1[0]=w1[3]=w1[7]=1;}
 else 
 for(i=0;i<3;i++)
 for(f1=0;f1<3;f1++) 
 if(f[i][f1]==' ') { f[i][f1]='O'; f2=1; break; }
}
++j; 
}while(j<10);
 e: cout<<"\nPress y to play again, press any other key to exit: "; c1=getch(); 
 if((c1=='y')||(c1=='Y')) {k++; goto d;}
 cout<<endl;
 if(s1>s2) cout<<"You win "<<s1<<'-'<<s2;
 else if(s2>s1) cout<<"CPU wins "<<s2<<'-'<<s1;
 else cout<<"Draw! "<<s1<<'-'<<s1;
 getch();
}
void t3() 
{ k=1; s1=0; s2=0; system("cls");
  cout<<"Player 1("; SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<'X'; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); 
  cout<<"), enter your name: "; cin>>na[0]; cout<<"Player 2("; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
  cout<<'O'; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<"), enter your name: "; cin>>na[1];
  d: i=0,j=0; char f[][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};  int w1[8]={},w2[8]={};
 do
{ system("cls");
cout<<"\t\t\tRound "<<k<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<"X: ";  SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); 
cout<<na[0]<<'-'<<s1<<"\n "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<"O: "; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<na[1]<<'-'<<s2<<endl; 
for(f1=0;f1<3;f1++) 
{ cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl<<'\t'<<char(179); 
  for(f2=0;f2<3;f2++) 
{ if(f[f1][f2]=='O') {SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY); cout<<'O';} else if(f[f1][f2]=='X') {SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY); cout<<'X';} else cout<<' '; 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);cout<<char(179);}
}
cout<<endl<<"\t "<<char(196)<<' '<<char(196)<<' '<<char(196)<<endl; 
if(j>=5) 
  { f2=-1; 
   for(f1=0;f1<8;f1++) 
   { if(!w1[f1]&&w2[f1]) 
	   switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='X')) f2=0; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='X')) f2=0; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[1][2]==f[2][2])&&(f[0][2]=='X')) f2=0; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='X')) f2=0; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][0]=='X')) f2=0; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='X')) f2=0; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='X')) f2=0; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='X')) f2=0; break;
	   }
	   else if(!w2[f1]&&w1[f1])
	   switch(f1)
	   { case 0: if((f[0][0]==f[1][0])&&(f[2][0]==f[1][0])&&(f[0][0]=='O')) f2=1; break;
	     case 1: if((f[0][1]==f[1][1])&&(f[2][1]==f[1][1])&&(f[0][1]=='O')) f2=1; break;
	     case 2: if((f[0][2]==f[1][2])&&(f[2][2]==f[1][2])&&(f[0][2]=='O')) f2=1; break;
	     case 3: if((f[0][0]==f[0][1])&&(f[0][1]==f[0][2])&&(f[0][2]=='O')) f2=1; break;
	     case 4: if((f[1][0]==f[1][1])&&(f[1][1]==f[1][2])&&(f[1][0]=='O')) f2=1; break;
	     case 5: if((f[2][0]==f[2][1])&&(f[2][1]==f[2][2])&&(f[2][0]=='O')) f2=1; break;
	     case 6: if((f[0][2]==f[1][1])&&(f[1][1]==f[2][0])&&(f[0][2]=='O')) f2=1; break;
	     case 7: if((f[0][0]==f[1][1])&&(f[2][2]==f[1][1])&&(f[0][0]=='O')) f2=1; break;
	   }
	   if(f2!=-1) 
	 {  cout<<na[f2]<<" wins!"; 
	   if(f2) ++s2; 
	   else ++s1;
	   break;
	 }
   }  
  if(f2!=-1) break;
  }
if(j++>=9) {cout<<"Round draw!\n"; break;} 
cout<<na[i%2]<<", it's your turn. Enter the row and column of the box. (Press Esc to Quit)"; b: c1=getch(); 
if(c1==27) { cout<<'\n'<<na[(i+1)%2]<<" wins!\n"; if(i%2) ++s1; else ++s2; goto e;  } if(isdigit(c1)) cout<<c1; else goto b; r=int(c1)-48; cin>>c; 
  if(f[r-1][c-1]!=' ') {cout<<"\nPlease choose a non empty box! ";  goto b;}
  f[r-1][c-1]=(i%2)?'O':'X'; 
  switch(r)
 { case 1:
  { if(i%2) w1[3]=1; else w2[3]=1;  
   if(c==1) if(i%2) {w1[0]=1; w1[7]=1;} else {w2[0]=1; w2[7]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[6]=1; } else {w2[2]=1; w2[6]=1; }
  } break;
   case 2:
   { if(i%2) w1[4]=1; else w2[4]=1;
    if(c==1) if(i%2) w1[0]=1;  else w2[0]=1; 
    else if(c==2) if(i%2) {w1[1]=1; w1[6]=1; w1[7]=1;} else {w2[1]=1; w2[6]=1; w2[7]=1;}
    else if(c==3) if(i%2) w1[2]=1; else w2[2]=1; 
  } break;
  case 3:
  { if(i%2) w1[5]=1; else w2[5]=1;
    if(c==1)  if(i%2) {w1[0]=1; w1[6]=1;} else {w2[0]=1; w2[6]=1;}
    else if(c==2) if(i%2) w1[1]=1; else w2[1]=1;
    else if(c==3) if(i%2) {w1[2]=1; w1[7]=1;} else {w2[2]=1; w2[7]=1;}
  } break;
  }
++i;
}while(j<10);
 cout<<"\nPress y to play again, press any other key to exit: "; c1=getch(); 
 if((c1=='y')||(c1=='Y')) {k++; goto d;}
 e: cout<<endl;
 if(s1>s2) cout<<na[0]<<" wins "<<s1<<'-'<<s2;
 else if(s2>s1) cout<<na[1]<<" wins "<<s2<<'-'<<s1;
 else cout<<"Draw! "<<s1<<'-'<<s1;
 getch();
}
void T()
{ do
{ system("cls"); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<char(233); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 cout<<"\n\n\t\t\t\tTIC TAC TOE:\n\n"; SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_RED); cout<<"\t  The classic game you play when the teacher isnt looking "; SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 cout<<char(2); 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 cout<<"\n\n\t\t\t\t1.CPU vs CPU\n\n\n\n\t\t\t\t2.CPU vs Human\n\n\n\n\t\t\t\t3.Human vs Human\n\n\n\n\t\t\t     Esc.Back to Main Menu\n\n"; 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(233);  SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\n\nEnter choice: "; ch=getch();
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
  switch(ch)
  { case '1': t1(); break;
    case '2': t2(); break;
    case '3': t3(); break;
    case 27: break;
  }
}while(ch!=27);
}
void st()
{char str[350]; ifstream fil("DP2.cpp"); v=0; while(fil.getline(str,350)) v++; system("cls"); ifstream f("DP2.cpp"); f.seekg(0,ios::end); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(15); cout<<endl; ifstream a("DP2.exe",ios::binary); a.seekg(0,ios::end);  
 SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\n\t\t\t\t  STATS"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 cout<<"\n\n\t\t\t   Previous reset: Never\n\n\n\t\t  Previous compile: "<<__TIME__<<", "<<__DATE__<<"\n\n\n\t\t\tNumber of lines in code: "<<v<<"\n\n\n\t\t\tSource Code size: "<<(float)f.tellg()/1024<<" KB\n\n\n";
 cout<<"\tApplication location: "<<__FILE__<<"\n\n\n"<<"\t\t\tApplication size: "<<(float)a.tellg()/(1024*1024)<<" MB\n\n\n"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(15); 
 SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\nPress any key to continue......\n"; getch(); 
 f.close(); a.close(); fil.close();
}
void cr()
{system("cls"); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<char(21); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 cout<<"\n\n\n\t\t\t\t  CREDITS\n\n\n"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
 cout<<"\t\t\t     Kunal Deb 12BCE0018\n\n\n\n\n\n\t\t\t    Kunal Nagpal 12BCE0398\n\n\n\n\n\n\t\t\t  Vikramraj Sitpal 12BCE0307\n\n"; 
 SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(21); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\n\nPress any key to continue.....\n"; getch();
}
void d()
{system("cls"); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<'#'; SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
 cout<<"\n\n\n\n\n\t\t\t\t    DISCLAIMER"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
cout<<"\n\n\n\t\t\tThe makers of this application are\n\n\t\t\tin no way responsible for the accuracy\n\n\t\t\tof the information contained herein.\n\n\t\t\t\tAll rights reserved.\n\n\n\n\n\n"; 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
 for(i=0;i<79;i++) cout<<'#'; SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\n\nPress any key to continue...\n"; getch();
}
main()
{ char ch; QueryPerformanceFrequency(&z); system("title CSE 220 Project II");
 do
 { system("cls");
   SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); for(i=0;i<79;i++) cout<<char(176); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
cout<<"\n\t\tApplication started at "<<ctime(&ti); SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  
for(i=0;i<79;i++) cout<<char(176); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY); cout<<"\n\n\n\t\t     The amazing world of graphs and trees\n"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
cout<<"\n\t\t\t\t1.Graph\n\n\t\t\t\t2.Tree\n\n\t\t\t\t3.Tic Tac Toe\n\n\t\t\t\t4.Statistics\n\n\t\t\t\t5.Credits\n\n\t\t\t\t6.Disclaimer\n\n\t\t\t\tEsc.Exit\n\n"; 
SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE); 
 for(i=0;i<79;i++) cout<<char(176); SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);  cout<<"\n\nEnter choice:"; SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
ch=getch();
  switch(ch)
  { case '1':g(); break;
    case '2':t(); break;
    case '3': T(); break;
    case '4': st(); break;
    case '5': cr(); break;
    case '6': d(); break;
    case 27: SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); system("cls"); cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tExiting in less than 1 second!"; Sleep(500); break;
  }
}while(ch!=27);
}
