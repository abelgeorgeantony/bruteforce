#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<fstream>
using namespace std;

int col=0,row=0;
char cword[4];
char wordstor[34500000][10];
char fwordstor[10];
const char characters[26] = {'a','b','c','d',
'e','f','g','h','i','j','k','l','m','n','o',
'p','q','r','s','t','u','v','w','x','y','z'};
const char numbers[10] = {'0','1','2','3',
'4','5','6','7','8','9'};
int lcount[20];
bool posloopcompl[20];
bool run = false,insigrun = true;

void shouldrunfstwhile(int);
void shouldinsigforrun();
void combinationcreator(int);
void wordvalidator();
void numberadder();

int main()
{
int noliw,i,j;
cout<<"Enter number of digits \n";
cin>>noliw;
row = 0;
cout<<"starting fst  while loop\n";
cout.flush();
sleep(1);
run = true;
while(run == true)
{
//cout.flush();
//usleep(5000);
//cout<<"while loop beginning\n";
combinationcreator(noliw);
for(i=0;i<noliw;i++)
{
 fwordstor[i] = cword[i];
}
shouldrunfstwhile(4);
wordvalidator();
}
cout<<"While loop finished\n";
cout<<"Ready to print words in wordstor array\n'y' to continue\n";
char uselessvar;
cin>>uselessvar;
ofstream fout("passlist.txt",ios::app);
for(j=0;j<=34500000;j++)
{
cout<<"word number "<<j<<"\n";
 for(i=0;i<6;i++)
 {
  cout<<wordstor[j][i];
  fout<<wordstor[j][i];
 }
cout.flush();
usleep(100);
fout<<"\n";
cout<<"\n---------\n";
}
fout.close();
cout<<"finished";
return(0);
}

void shouldrunfstwhile(int liw)
{
int c,loccounter = 0;
for(c=0;c<liw;c++)
{
 if(cword[c] == 'z')
 {
  loccounter++;
 }
}

if(loccounter == liw)
{
 run = false;
}
else
{
 run = true;
}

}

void combinationcreator(int nliw)
{
 nliw--;

 if(nliw > 0)
 {
  combinationcreator(nliw);
 }
col=nliw;

 if(col==0)
 {

  if(fwordstor[col] == 'z')
  {
   lcount[col] = 0;
   cword[col] = characters[lcount[col]];
   lcount[col]++;
   posloopcompl[col] = true;
  }

  else
  {
   cword[col] = characters[lcount[col]];
   lcount[col]++;
   posloopcompl[col] = false;
  }

 }
 else if((col>0)&&(col<4))
 {

  if(posloopcompl[col-1] == true)
  {
   if(fwordstor[col]=='z')
   {
    lcount[col]=0;
    cword[col] = characters[lcount[col]];
    posloopcompl[col] = true;
   }
   else
   {
    lcount[col]++;
    cword[col] = characters[lcount[col]];
    posloopcompl[col] = false;
    posloopcompl[col-1] = false;
   }
  }
  else if(posloopcompl[col-1] == false)
  {
   cword[col] = characters[lcount[col]];
  }

 }
 else
 {
  return;
 }
}



void wordvalidator()
{
 if((cword[0]==cword[1])||(cword[0]==cword[2])||(cword[0]==cword[3]))
 {
  row = row;
 }
 else if((cword[1]==cword[2])||(cword[1]==cword[0])||(cword[1]==cword[3]))
 {
  row = row;
 }
 else if((cword[2]==cword[3])||(cword[2]==cword[0])||(cword[3]==cword[1]))
 {
  row = row;
 }
 else if((cword[3]==cword[0])||(cword[3]==cword[1])||(cword[3]==cword[2]))
 {
  row = row;
 }
 else
 {
  insigrun = true;
  while(insigrun == true)
  {
   numberadder();
   shouldinsigforrun();
   row++;
  }
 }
}

void numberadder()
{
 for(int i=0;i<4;i++)
 {
  wordstor[row][i]=cword[i];
 }
 if(wordstor[row-1][4] == '9')
 {
  lcount[4]=0;
  wordstor[row][4] = numbers[lcount[4]];
  lcount[4]++;
  posloopcompl[4] = true;
 }
 else
 {
  wordstor[row][4] = numbers[lcount[4]];
  lcount[4]++;
  posloopcompl[4] = false;
 }
 if(posloopcompl[4]==true)
 {
  if(wordstor[row-1][5] == '9')
  {
   lcount[5]=0;
   wordstor[row][5] = numbers[lcount[5]];
  }
  else
  {
   lcount[5]++;
   wordstor[row][5] = numbers[lcount[5]];
  }
 }
 else if(posloopcompl[4]==false)
 {
  wordstor[row][5] = numbers[lcount[5]];
 }
//cout<<"numbered word created :\n";
//for(int i=0;i<6;i++)
// {
//  cout<<wordstor[row][i];
// }
//cout<<"\n";
//cout.flush();
//usleep(10000);
}

void shouldinsigforrun()
{
 if((wordstor[row][4]==wordstor[row][5])&&(wordstor[row][5]=='9'))
 {
  insigrun=false;
//cout<<"word validator finished\n";
//cout.flush();
//sleep(5);
 }
 else
 {
  insigrun = true;
 }
}
