#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
struct block
{
 double x1,y1; //x2=780; y2=270;
};
void blocks(double ,double,double);
void jump()
{
int cnt=0,r=10,speed=1,go=0,score=0,cnst=0,level=150;
double x=50,y=200,acc=0;
circle(x,y,r);
char c;
double q[3],s[3];
for(int i=0;i<3;i++)
{
q[i]=640+i*213;
s[i]=100+random(level)-random(level-30);
}
while(c!='q'&&go==0&&y<470&&y>0)
{
gotoxy(30,1);
cout<<score;
while(!kbhit()&&go==0&&y<470&&y>0)
{
acc+=0.02;
cnst++;
if(q[0]==50)
score++;
if(q[0]<-60)
{
for(i=0;i<2;i++)
{
q[i]=q[i+1];
s[i]=s[i+1];
}
q[2]=580;
s[2]=100+random(level)-random(level-30);
}
for(i=0;i<3;i++)
blocks(q[i]--,s[i],1);
setcolor(0);
circle(x,y,r);
if(cnst%2==0)
line(x,y,x-r-4,y-3);
else
line(x,y,x-r-4,y+3);
//setfillstyle(1,0);
//floodfill(x+1,y+1,0);
y+=.75+acc;
setcolor(15);
circle(x,y,r);
if(cnst%2==0)
line(x,y,x-r-4,y+3);
else
line(x,y,x-r-4,y-3);
//setfillstyle(1,15);
//floodfill(x+1,y+1,15);
delay(speed);
if(x+r>q[0]&&x+r<q[0]+60&&y-r<s[0]||y+r>s[0]+90&&x+r>q[0]&&x+r<q[0]+60)
go=1;
}
c=getch();
if(c==32)
{
cnt=0;
while(cnt<50&&go==0&&y<470&&y>0)
{
cnst++;
acc=0;
if(q[0]==50)
score++;
if(q[0]<-60)
{
for(i=0;i<2;i++)
{
q[i]=q[i+1];
s[i]=s[i+1];
}
q[2]=580;
s[2]=100+random(level)-random(level-30);
}
for(i=0;i<3;i++)
blocks(q[i]--,s[i],1);
setcolor(0);
circle(x,y,r);
if(cnst%2==0)
line(x,y,x-r-4,y-3);
else
line(x,y,x-r-4,y+3);
//setfillstyle(1,0);
//floodfill(x+1,y+1,0);
cnt++;
y-=.95;
setcolor(15);
circle(x,y,r);
if(cnst%2==0)
line(x,y,x-r-4,y+3);
else
line(x,y,x-r-4,y-3);
//setfillstyle(1,15);
//floodfill(x+1,y+1,15);
delay(speed);
if(x+r>q[0]&&x+r<q[0]+60&&y-r<s[0]||y+r>s[0]+90&&x+r>q[0]&&x+r<q[0]+60)
go=1;
}}}
}
void blocks(double q,double s,double min)
{
 block b;
 b.x1=q; b.y1=s;
   setcolor(0);
   rectangle(b.x1,  0,  b.x1+40,  b.y1);
  floodfill(b.x1+1,1,0);
   rectangle(b.x1, b.y1+90, b.x1+40,480);
   floodfill(b.x1+1,470,0);
   delay(1);
   setcolor(3);
   setfillstyle(7,3);
   rectangle(b.x1-min,  0,  b.x1+40-min,  b.y1);
   floodfill(b.x1+2,1,3);
   rectangle(b.x1-min, b.y1+90, b.x1+40-min,480);
   floodfill(b.x1+2,470,3);



}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
char ch;
settextstyle(8,0,4);
outtextxy(70,150,"WELCOME TO THE FLYING BALL");
outtextxy(170,180,"CREATED BY");
outtextxy(100,210,"Humans");
outtextxy(400,400,"CONTINUE....");
getch();
while(ch!='n')
{
cleardevice();
jump();
cleardevice();
outtextxy(200,200,"GAMEOVER");
outtextxy(150,230,"PLAY AGAIN (Y/N)??");
ch=getch();
}
getch();
closegraph();


}
