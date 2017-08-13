#include<iostream.h>
#include   <conio.h>
#include    <time.h>
#include<graphics.h>
#include  <stdlib.h>
#include     <dos.h>
#include    <math.h>
#include  <string.h>
#include <fstream.h>
#include  <stdio.h>



class asteroid                                                    //class for controlling asteroid
 {     public:
      int bx,by ;
      char *ast;                                                                                 
      int token ;
      void dispast(int a, int b, char *c)
     {outtextxy( a, b, c);
     outtextxy( a+1, b, c);
     outtextxy( a, b+1, c);
     outtextxy( a-1, b, c);
     outtextxy( a, b-1, c);
   }
};
asteroid b[50];

class highscore                                                  // class for high score
{
public:
char name[20];
int highscr;
};
highscore hgscr[5], hgscr2[5], sid, reseter;


void display (int a, int b);                             //function to display drone 
void display2 (int a, int b);                            //function to display ufo
void display3 (int a, int b);                            //function to display tank
void display4 (int a, int b);                            //function to display fighter jet 
void reset();                                            //function to sort highscore 
void highreset();                                        //function to reset highscores
void transition();                                       //function for transition of screen in change shooter  
int disp=1;
char newname[20];                                        //name for setting new high score
int newscore;                                            //score to set new high score

void main ()
{
       fstream fix;
       fix.open("highscore.dat", ios::in| ios::binary);
       for(int i=0; i<5; i++)
       {fix.read((char*)&hgscr[i], sizeof(hgscr[i]));}      //to read saved high score
       fix.close();

       int gd=DETECT, gm;
       initgraph(&gd, &gm, "");


	void splpow(int xco, int yco);   //special power function
	void cheat( int &spl);
	int mission();
	char menu();                                                             // menu function
	void help();                                                             //instruction function
	void start();                                                             // starting video
	void end();                                                              //end(THANK YOU)
	void highscore();
	char * nameinput();
	int shooter( int &disp);
	cleardevice();
	start();

	again :
	newscore=0;
	char mnopt;
	int initime=45, lvl=20, lvlno=1, modedec, timestop=0, timefinal;
	int lvltime=initime;                         //time for different levels
	int check;
	re:
	closegraph();
	initgraph(&gd, &gm, "");
	cleardevice();
	mnopt=menu();                               // value assigned to mnopt by taking input in menu function
	int score=0;
	nxtlvl:
	randomize();
	char gunlimit=0;
	for (int sa = 0;sa<lvl;sa++)
	{
		b[sa].bx= 15 + random(getmaxx()- 30) ;                                            //asigning asteroids coordinates
		b[sa].by=(rand()%300)+55;
	}
	for (sa=0;sa<lvl;sa++)
		b[sa].token = 0;
	for (sa=0;sa<lvl;sa++)
		b[sa].ast = "*" ;
	 char ch ;
	time_t start_time1;                                                                              //Time initialise
	time_t stop_time1;
	time_t start_time2;
	time_t stop_time2;
	int e=0,spl=0;
	int posx=300,posy =400 ;
	if(mnopt=='1')
	{
	 closegraph();
	 int gd=DETECT, gm;
	   initgraph(&gd, &gm, "");

		if(lvlno>11)                                                                            //max no of levels 10
		{
		outtextxy( 300,170,"CONGRATULATIONS!! You have won the game");
		}
		else
		{
			cleardevice();
			if(lvlno==1)
			{
			strcpy(newname, nameinput());
			modedec = mission();}
			closegraph();
			int gd=DETECT, gm;
			initgraph(&gd, &gm, "");
			cleardevice();
			char lvlno2[10];
			setbkcolor(4);
			itoa(lvlno, lvlno2, 10);
			outtextxy (300,100, "LEVEL ");
			outtextxy (345, 100, lvlno2);
			char enter ;
			outtextxy (200, 170, "Enter 'n' to start the game ");
			outtextxy (200, 190, "Or any other key to exit ");
			gotoxy(40, 16);
			cin>> enter ;
		if (enter=='n' || enter=='N')                                        //start game

		  {
		cleardevice();
		setbkcolor(0);
		check=0;
		start_time1 = time (NULL);                                                                                                       // Time starter
		}
		else return ;

	long k = 0;
	while(k<10000)                                                                                       // main loop
	{
	   if(k%5==0)
	     { splpower:
	      cleardevice();  }

	       outtextxy(1, 50 ,"-------------------------------------------------------------------------------");

		if (modedec==1)
		   {for (sa = 0;sa<lvl;sa++)
		     {b[sa].dispast(b[sa].bx,b[sa].by,b[sa].ast  ) ;}                                                               //printing asteroid on output screen
		   }
		else if (modedec==2)
		   {for (sa = 0;sa<lvl;sa++)
		     {if(b[sa].bx>=(getmaxx()-20))
			{b[sa].bx = b[sa].bx;}
		      else if(b[sa].bx<=15)
			{ b[sa].bx=b[sa].bx;}
		      else if(k%50==0)
			{b[sa].bx=b[sa].bx+random(31)-20;}
		   b[sa].dispast(b[sa].bx,b[sa].by,b[sa].ast  ) ;}                                                               //printing asteroid on output screen
		 }
		 if(disp==1)
		 {display(posx, posy);}
		 else if(disp==2)
		 {display2(posx, posy);}
		 else if(disp==3)
		 {display3(posx, posy);}
		 else if(disp==4)
		 {display4(posx, posy);}

		char e2[5], gun2[5], score2[30], lvltime2[5];
		itoa(lvltime, lvltime2, 10);
		itoa(e,e2, 10);
		itoa(gunlimit, gun2, 10);
		itoa(score, score2, 10);

		outtextxy (10,35, "TIME - ");
		outtextxy (60, 35, e2);
		outtextxy (79, 35, "/");
		outtextxy (85, 35, lvltime2);
		outtextxy (100, 35, "  Bullet No. - " );
		outtextxy (220, 35, gun2);
		outtextxy (240, 35, "/100 ");
		outtextxy ( 300, 35, "SCORE - ");
		outtextxy (360, 35, score2);

		if(kbhit()!=0)
		{ch=getch ();
		if (ch=='q')
		end() ;
		if (ch=='c')
		{ stop_time1 = time(NULL);
		 cheat(spl);
		start_time2 = time(NULL);
		timestop = difftime(start_time2, stop_time1);
		goto splpower;}

		if (ch==75 )                                        //changing x coordinate of shooter (right)
		{
			posx = posx - 3;
			if (posx<=0)
			{posx=posx +3;}
			cleardevice();
			if(disp==1)
			{display (posx, posy);}
			else if (disp==2)
			{display2 (posx, posy);}
			else if (disp==3)
			{display3 (posx, posy);}
			else if (disp==4)
			{display4 (posx, posy);}

		}
		if (ch==77)                                       //changing x coordinate of the shooter (left)
		{
			posx=posx+3;
			if (posx>=getmaxx())
			{posx=posx-3;}
			cleardevice();
			if (disp==1)
			{display(posx, posy);}
			else if(disp==2)
			{display2 (posx, posy);}
			else if (disp==3)
			{display3 (posx, posy);}
			else if (disp==4)
			{display4 (posx, posy);}

		}
		int l = posx ;
		int flag=0;
		if (ch==72 )                                                                                       //shooting gun
		{       cleardevice();
			gunlimit++;
			for (int gun =400;gun >50;gun-=1)                                                                         // loop for bullet
			 {
			for(sa=0;sa<lvl;sa++)
				{
					if (b[sa].token ==0 )
					{
						if (((b[sa].bx>=l-5)&&(b[sa].bx<=l+5) )&& b[sa].by==gun)                        //for same coords
						{             //gun          //bullet

							b[sa].ast++;                                            //destroy bullet
							b[sa].token=b[sa].token +1;                   //token - flag1
							check++;
							flag=flag +1 ;
							if(modedec==1)
							{score+=(flag*(lvltime-e));}
							else if(modedec==2)
							{score+=(2*flag*(lvltime-e));}                       //to get score
							cleardevice();
						       for (sa = 0;sa<lvl;sa++)
					{b[sa].dispast (b[sa].bx,b[sa].by,b[sa].ast  ) ;}                                                               //printing asteroid on output screen
					if (disp==1)
					{display( posx, posy);}
					else if(disp==2)
					{display2 (posx, posy);}
					else if (disp==3)
					{display3 (posx, posy);}
					else if (disp==4)
					{display4 (posx, posy);}


					outtextxy (10,35, "TIME - ");
					outtextxy (60, 35, e2);
					outtextxy (79, 35, "/");
					outtextxy (85, 35, lvltime2);
					outtextxy (100, 35, "  Bullet No. - " );
					outtextxy (220, 35, gun2);
					outtextxy (240, 35, "/100 ");
					outtextxy ( 300, 35, "SCORE - ");
					outtextxy (360, 35, score2);




							break;

						}
					if (flag>0)
					b[sa].ast=" ";

					}
				}
			  if (flag!=0)
			    {break ;}
			      if(gun%20==0)
			     {	outtextxy(l,gun, "|");
				delay (10);
			       cleardevice();
			outtextxy(1,50,"-------------------------------------------------------------------------------");
			if (modedec==1)
			{for (sa = 0;sa<lvl;sa++)
			{b[sa].dispast (b[sa].bx,b[sa].by,b[sa].ast  ) ;}                                                               //printing asteroid on output screen
			}
			else if (modedec==2)
			{
			{
			if(b[sa].bx>=(getmaxx()-20))
			{ b[sa].bx = b[sa].bx;}
			else if(b[sa].bx<=15)
			{ b[sa].bx=b[sa].bx;}
			else if(gun%400==0)
			{b[sa].bx=b[sa].bx+random(31)-20;}
			for (sa = 0;sa<lvl;sa++)
			{b[sa].dispast (b[sa].bx+random(11)-5,b[sa].by,b[sa].ast  ) ;}                                                               //printing asteroid on output screen
			}
			}
			if(disp==1)
			{display(posx, posy); }
			else if (disp==2)
			{display2(posx, posy);}
			else if (disp==3)
			{display3(posx, posy);}
			else if (disp==4)
			{display4(posx, posy);}

			outtextxy (10,35, "TIME - ");
			outtextxy (60, 35, e2);
			outtextxy (79, 35, "/");
			outtextxy (85, 35, lvltime2);
			outtextxy (100, 35, "  Bullet No. - " );
			outtextxy (220, 35, gun2);
			outtextxy (240, 35, "/100 ");
			outtextxy ( 300, 35, "SCORE - ");
			outtextxy (360, 35, score2);

			}
			}

		}

		if (ch=='m' &&spl> 0)                                                            //use of special power
		{


			splpow(posx, posy);                                                        //Funct for spl power
			delay(200);
			cleardevice();
			char option;
			setbkcolor(1);
			outtextxy( 300,150, "YOU WIN!! ");
			outtextxy(250, 160, "ALL ASTEROIDS ARE DESTROYED");
			outtextxy(300, 180, "Your score is  " );
			char score3[5];
			itoa( score, score3, 10);
			 outtextxy( 320, 190, score3);
			abc:
			outtextxy(250, 210, "Enter 'y' to play again and 'q' to quit ");
			outtextxy(250, 230, "Enter 'n' for next level ");
			gotoxy(35, 24);
			cin>>   option ;
			if(option =='y')
			{       if(score>hgscr[4].highscr)
				{newscore=score;
				reset();}
				closegraph();
				goto again ;
			}
			if (option == 'q')
			{    if(score>hgscr[4].highscr)
			     {newscore=score;
			     reset();}
			     end();
			}
				if (option== 'n')
			{
			lvlno++;
			lvl+=4;
			lvltime+=2;
			goto nxtlvl;
			}
			else
			{       cleardevice();
				outtextxy(250, 210, " Wrong Choice ") ;
				delay(1000);
				cleardevice();
			goto abc;
			}
		}
		}
		if (gunlimit==100)                                                                                                                      //Bullet used limit
		{
			cleardevice();
			char option;
			setbkcolor(1);
			if(score>hgscr[4].highscr)
			{newscore=score;
			reset();}
			outtextxy(300, 150, "YOU LOOSE");
			outtextxy(250, 160, "GUN LIMIT REACHED");
			outtextxy(300, 170, "Your score is ");
			char score2[5];
			itoa(score, score2, 10);
			outtextxy(320, 180, score2);
			abc2:
			outtextxy(200, 210, "Enter 'y' to play again and 'q' to quit ");
			gotoxy(40, 21);
			cin>>     option ;
			if(option =='y')
			{       closegraph();
				goto again ;
			}
			if (option == 'q')
			{
			end();
			}
				else
			{       cleardevice();
				outtextxy (250, 210, " Wrong Choice " );
				delay(1000);
				cleardevice();
				goto abc2;
			}
		}
		int check2=0;
		for(sa=0;sa<lvl;sa++)
		{
			if (strcmp(b[sa].ast, " ")==0)
			check2 ++;
			else
			continue ;
		}

		if (check == lvl-2)
		{
			spl ++;                                                                                                            //to access spl power
		}
		if(check==lvl)                                                                                                                      //For checking asteroid left
		{
			cleardevice ();
			char option;
			setbkcolor(1);
			outtextxy (300, 150, "YOU WIN ");
			outtextxy (250, 160, "ALL ASTEROIDS ARE DESTROYED");
			outtextxy (300, 170, "Your score is  " );
			char score2[5];
			itoa(score, score2, 10);
			outtextxy (320, 180, score2);
			abc4:
			outtextxy(200, 210, "Enter 'y' to play again and 'q' to quit ");
			outtextxy(200, 230, "Enter 'n' for next level ");
			gotoxy(40, 24);
			cin>> option ;

			if(option =='y')
			{       if(score>hgscr[4].highscr)
				{newscore=score;
				reset();}
				closegraph();
				goto again ;
			}
			if (option == 'q')
			{   if(score>hgscr[4].highscr)
			    {newscore=score;
			    reset();}
			    end();
			}
			if (option== 'n')
			{     lvlno++;
			lvl+=4;
			lvltime+=2;
			goto nxtlvl;
			}

			else
			{       cleardevice();
				outtextxy (250, 210,  " Wrong Choice ") ;
				delay(1000);
				cleardevice();
				goto abc4;
			}
			}
		stop_time2 = time(NULL);
		timefinal = difftime(stop_time2 ,start_time1 );
		e=timefinal-timestop;
		outtextxy (10,35, "TIME - ");
		outtextxy (60, 35, e2);
		outtextxy (79, 35, "/");
		outtextxy (85, 35, lvltime2);
		outtextxy (100, 35, "  Bullet No. - " );
		outtextxy (220, 35, gun2);
		outtextxy (240, 35, "/100 ");
		outtextxy ( 300, 35, "SCORE - ");
		outtextxy (360, 35, score2);

		if (e==lvltime)                                                                                                                                                            //for checking lvl time
		{
			cleardevice ();
			char option;
			setbkcolor(1);
			if(score>hgscr[4].highscr)
			{newscore=score;
			reset();}
			outtextxy (300, 150, "YOU LOOSE");
			outtextxy (300, 170, "TIME OVER ");
			outtextxy (250, 190, "Your score is:");
			outtextxy (300, 200, score2);
			abc3:
			outtextxy (200, 220,  "Enter 'y' to play again and 'q' to quit ");
			gotoxy(40, 24);
			cin>>option ;
			if(option =='y')
			{      closegraph();
				goto again ;
			}
			if (option == 'q')
			{
			end();
			}
				else
			{       cleardevice();
				outtextxy (250, 210,  " Wrong Choice ") ;
				delay (1000);
				cleardevice();
				goto abc3;
			}


		    }
		k++;
		}

	      }

	    }
	else if(mnopt=='2')                                                                                                                                              //Menu opt 2
	  {help();
	  goto again;}

	else if(mnopt=='3')
	  {shooter(disp);
	  closegraph();
	  int gd=DETECT, gm;
	  initgraph(&gd, &gm, "");
	   goto again;}
	else if(mnopt=='4')
	{highscore();
	closegraph();
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	goto again;}
	else if(mnopt=='5')
	  { end(); }
	else
	  { goto re;}

getch ();
}



//functions:
void help()                                                                                                                                                                                                                                                 //funct for help menu
{       closegraph();
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	setfillstyle(SOLID_FILL, RED);
	int poly[8]={25, 120, 620, 120, 620, 360, 25, 360 };
	fillpoly(4, poly);
	setcolor(14);
	int ibro=0;
	while ( ibro<500 )
	{
		delay(20);
		setcolor(6);
	setcolor(5);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	circle((rand()%650),(rand()%550), 1);
	if(ibro%75==0)
	{

		setfillstyle(SOLID_FILL, RED);
		int poly[8]={15, 40, 625, 40, 625, 430, 15, 430 };
		fillpoly(4, poly);
		setcolor(14);
		outtextxy(240, 65-10, "INSTRUCTIONS");
		outtextxy(20, 75-10, "1. The first level of the game consists of 20 asteroids ");
		outtextxy(20, 85-10, "   and a shooter. Your aim is to simply destroy all the " );
		outtextxy(20, 95-10, "   asteroids within the time limit (i.e 45 seconds). ");
		outtextxy(20, 105-10, "   Keeping in mind that you only have 100 bullets in the first level ");
		outtextxy(20, 115-10, "2. As your level increases, the number of asteroids will increase by 2");
		outtextxy(20, 125-10, "   for every level. And also the no. of bullets allowed to use decreases"  );
		outtextxy(20, 135-10, "   by 5 for every level");
		outtextxy(20, 145-10, "3. If you fail to destroy all the asteroids in the given time limit with ");
		outtextxy(20, 155-10, "   the given bullets you will loose ");
		outtextxy(20, 165-10, "4. After you have destroyed all the asteroids, but only 2 are remaining ");
		outtextxy(20, 175-10, "   you will be allowed to use a special power which will instantaneously ");
		outtextxy(20, 185-10, "   destroy all the remaining asteroids  ");
		outtextxy(20, 195-10, "5. You can press 'q' at any time to exit the game");
		outtextxy(240, 225-10, "CONTROLS");
		outtextxy(20, 235-10, "Use the UP ARROW to shoot." );
		outtextxy(20, 245-10, "Use LEFT ARROW and RIGHT ARROW key to move in the respective directions. " );
		outtextxy(20, 255-10, "Press 'm' to use special power (only when 2 asteroids left). ");
		outtextxy(240, 285-10, "EXTRA");
		outtextxy(20, 295-10,  "--> You have the option of choosing between the 2 difficulty modes:");
		outtextxy(20, 305-10,  "* Easy Mode: The asteroids remain at their position and they are to be");
		outtextxy(20, 315-10,  "             destroyed within the given time limit");
		outtextxy(20, 325-10,  "* Advanced Mode: The asteroids move randomly about their original position ");
		outtextxy(20, 335-10,  "             and have the ability of dodging the bullets and are much more ");
		outtextxy(20, 345-10,  "             to be destroyed in the given time limit. This is a level ");
		outtextxy(20, 355-10,  "             designed especially for experts.");
		outtextxy(20, 365-10,  "--> If the game is too much of a challange for you, you can easily ");
		outtextxy(20, 375-10,  "    activate the special power at any time by pressing 'c' and entering ");
		outtextxy(20, 385-10,  "    the cheat code  'iamacheater'. But don't make using the cheat a habit");
		outtextxy(20, 395-10,  "--> If you don't like your current shooter, press '3' on the Menu Screen");
		outtextxy(20, 405-10,  "    and choose your favourite shooter.");
		outtextxy(190, 425-10, "HOPE YOU ENJOY YOUR GAMING EXPERIENCE!!");
		int poly2[8]={340,450, 635, 450, 635, 470, 340, 470};
		fillpoly(4, poly2);
		setcolor(14);
		outtextxy(345, 455,"Enter any key to return to main menu.");
	 if(kbhit()!=0)
	 {goto exiting;}
	}
     ibro++;
     }
  getch();
  exiting:
 closegraph();
}



void splpow(int xco, int yco)                                                                                        //spl power func
{ closegraph();
  int gd=DETECT, gm;
  initgraph(&gd, &gm, "");
  for(int bro=1; bro<=20; bro++)
    { outtextxy (b[bro].bx,b[bro].by,b[bro].ast  ) ;}
  if( disp==1)
  display(xco,yco);
  else if(disp==2)
  display2 (xco, yco);
  else if (disp==3)
  display3 (xco, yco);
  else if (disp==4)
  display4 (xco, yco);

  for (double pow=30; pow<700; pow+=1)
    {delay(4);
     circle(xco+4,yco,pow);}
  delay(1000);
}




char menu()
{
  cleardevice();
  int x=635, y=470, up=15;
  char x2;
  closegraph();
  int gd=DETECT, gm;
  initgraph(&gd, &gm, "");
  setbkcolor(0);
  line(0,up,x,up);
  line(0,y,x,y);
  line(up,0,up,x);
  line(x-15,0,x-15,x);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
  outtextxy(250,140, "SPACE IMPACT");
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
  outtextxy(290, 170, "MENU");
  outtextxy(230, 190, "1. Start New Game");
  outtextxy(230, 210, "2. Instuctions/ Help");
  outtextxy(230, 230, "3. Change Shooter");
  outtextxy(230, 250, "4. High Score");
  outtextxy(230, 270, "5. Exit");
  double i;
  int i2;
   for(i=0.0, i2=0; i<100;i2++, i+=0.01)
     {delay(0.6);
     int upz=up-sin(i)*7;
     int z=y-sin(i) *7;
     int b=i*7;
     setcolor(15);
     fillellipse(upz, b, 0.2, 0.2);
     fillellipse(z+150, b,0.2, 0.2);
     fillellipse(b, upz, 0.2, 0.2);
     fillellipse(b, z,0.2, 0.2);
       if(i2%5==0)
	{
	setcolor(6);
	setcolor(5);
	circle((rand()%650),(rand()%550), 0.2);
	}


      if(kbhit()!=0)
      {x2=getch();
      goto chosen;}
      }
  x2=getch();
  chosen:
  closegraph();

  return(x2);
}



void start()
{
  int gd=DETECT, gm;
  initgraph(&gd, &gm, "");
  for(int end=450; end> 100; end--)
   {
   if(end>200)
     {
     if(end%5==0)                                                                                    //shooter shooting asteroid(start video)
       {
       delay(60);
       cleardevice();
       setcolor(15);
       if(disp==1)
       display(325, 450);
       else if(disp==2)
       display2 (325, 450);
       else if (disp==3)
       display3 (325, 450);
       else if (disp==4)
       display4 (325, 450);
       outtextxy(325, 200, "*");
       outtextxy(325, end, "|");
       }
     }
   else if(end==200)                                                                   //bullet hits ast (start video)
     {
      for(int end2=0; end2<400; end2++)
	{setcolor(15);
	if(end2%5==0)
	  {delay(60);
	  if(end2%10==0)
	  {cleardevice();}
	  setcolor(15);
	  for (int j=0; j<=60; j++)
	    {circle(325, 200, end2+j);  }
	  if(end2>125 && end2<275)
	   {
	   delay(60);
	   setcolor(15);
	   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	   outtextxy(250,180, "SPACE IMPACT");
	   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	   outtextxy(170,220, "ITS MUCH MORE THAN JUST A GAME");
	   }
	  if(end2>275&&end2<375)
	  {delay(60);
	  setcolor(15);
	  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	  outtextxy(250, 200, "ITS A JOURNEY!!");
	   }
	 if(end2>390)
	 {goto credits;}
       }
     }
   }
 }
 credits:
 cleardevice();
 for(int cre=0; cre<310;cre++)
  {if(cre%5==0)
  {delay(30);
  cleardevice();
  setbkcolor(2);
  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
  outtextxy(cre-40,310 , "PRESENT");
  outtextxy((625-cre-70), 190, "NIMIT AGGARWAL");
  outtextxy(cre, 230, "&");
  outtextxy((625-cre-100), 270, "SIDDHARTH KOTHIYAL");
  }
 }

 getch();
 closegraph();
}




void end()
{       closegraph();
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "");
	cleardevice();
	for(int final=0; final<250; final++)
{       delay(8);
	cleardevice();
	setbkcolor(4);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	outtextxy(50, 425- final, "THANK YOU FOR PLAYING!!");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	outtextxy(150, final, "HOPE YOU ENJOYED !!" );
}
	getch();
	exit(0);
}




int mission()
{ int mode;
  closegraph();
 int gd= DETECT, gm;
 initgraph(&gd, &gm, "");
	setbkcolor(1);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(250, 200, "Select Difficulty: ");
	outtextxy(250, 220, "1. Easy Mode");
	outtextxy(250, 240, "2. Advanced Mode");
	gotoxy(40, 18 );
	cin>>mode;
	closegraph();
return(mode);
}

void display( int posx, int posy )
{
		outtextxy (posx,posy, "S");
		outtextxy (posx, posy -2, "S");
		outtextxy (posx,posy -4, "S");
		outtextxy (posx, posy -6, "S");
		outtextxy (posx,posy -8, "S");
		outtextxy (posx, posy -10, "S");
		outtextxy (posx,posy -12, "S");
		outtextxy (posx, posy -14, "S");
		outtextxy (posx+5, posy-8, "--");
		outtextxy (posx -13, posy-8, "--");
		outtextxy (posx-15, posy-8, "I");
		outtextxy (posx+15, posy-8, "I");
}




void cheat(int &spl)
{
  char cheater[20];
  cleardevice();
  setbkcolor(1);
  outtextxy(240, 200, " Enter the cheat ");
  gotoxy(35,20);
  gets(cheater);
  cleardevice();
  setbkcolor(1);
  if(strcmp(cheater, "iamacheater")==0)
    {spl++;
    outtextxy(200, 250, " The cheat code entered is correct.");
    outtextxy(200, 260, "  Special power has been enabled. ");
     }
  else
     {outtextxy(200, 250, " The cheat entered is incorrect.");
     outtextxy(200, 260, " Cheating is a bad habit!! :-P ");
     }
  outtextxy(200, 280, " Press any key to exit. ");

 getch();
 cleardevice();
 setbkcolor(0);
}

void display2 (int posx, int posy)
 {
 for(float i=0.0; i<=7;i+=0.5)
	 { circle(posx, posy, i);}
	 for (i=11.0; i<=15; i+=0.5)
	 { circle(posx, posy, i);}
 }

void display3 (int posx, int posy)
{
  int  poly1[8]={posx-10, posy-20, posx-10, posy+20, posx+10, posy+20, posx+10, posy-20};
  setfillstyle( SOLID_FILL, 2);
  fillpoly (4, poly1);
  for(int i=3; i<5;i++)
   { setcolor(0);
   circle(posx, posy+5, i);}
  for(i=-1; i<=1;i++)
   {setcolor(1);
   line(posx+i, posy, posx+i, posy-15);}
  setcolor(15);
}

void display4 (int posx, int posy)
{
  int poly2[6]={posx, posy-25, posx-15, posy+20, posx+15, posy+20};
  setfillstyle( SOLID_FILL, 2);
  fillpoly(3, poly2);
  setfillstyle(SOLID_FILL, 0);
  fillellipse(posx, posy+10, 5, 5);
  int poly3[6]={posx, posy+5, posx-5, posy+35, posx+5, posy+35};
  fillpoly(3, poly3);
  setcolor(0);
  for(int i=0; i<=5; i++)
    {circle(posx, posy+10, i);}
  for(i=0; i<20; i++)
    {line(posx-15, posy+20+i, posx+15, posy+20+i);}
  setcolor( 15);
}

void transition()
{
  setbkcolor(0);
  for(int i =0; i<=getmaxx(); i++)
    {setcolor(0);
    delay(1);
    line(i, 0, i, getmaxy());
    }
  for( i=0; i<=getmaxx(); i++)
    {int k=i%15;
    setcolor(k);
    delay(1);
    line(0, i, getmaxx()/2 ,getmaxy()/2);
    line(i, 0, getmaxx()/2, getmaxy()/2);
    line(getmaxx()-i, getmaxy(), getmaxx()/2, getmaxy()/2);
    line(getmaxx(), getmaxy()-i, getmaxx()/2, getmaxy()/2);
    }
   bar (getmaxx()/2-50, getmaxy()/2-50, getmaxx()/2+50, getmaxy()/2+50);
   int  poly[8]={(getmaxx()/2)-150, (getmaxy()/2)-150, (getmaxx()/2)-150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)-150};
   int poly4[8]={getmaxx()-150, 200, getmaxx(), 200, getmaxx(), 300, getmaxx()-150, 300};
   int poly5[8]={getmaxx()-160, 350, getmaxx(), 350, getmaxx(), 405, getmaxx()-160, 405};
   setfillstyle( SOLID_FILL, 0);
   fillpoly (4, poly5);
   fillpoly (4, poly);
   fillpoly (4, poly4);
   settextstyle(0,0,1);
   outtextxy(getmaxx()-120, 225, "Enter the code");
   outtextxy(getmaxx()-120, 235, "of the shooter");
   outtextxy(getmaxx()-135, 245, "1. DRONE");
   outtextxy(getmaxx()-135, 255, "2. UFO ");
   outtextxy(getmaxx()-135, 265, "3. TANK");
   outtextxy(getmaxx()-135, 275, "4. FIGHTER JET");
   outtextxy(getmaxx()-150, 360, "Choose the shooter");
   outtextxy(getmaxx()-150, 370, "and press any");
   outtextxy(getmaxx()-150, 380, "other button to");
   outtextxy(getmaxx()-150, 390, "select and leave.");
}




int shooter(int &disp)
{ char shoot;
closegraph();
 int gd= DETECT, gm;
 initgraph(&gd, &gm, "");
 setbkcolor(0);
 int k;
 for(int i=0; i<=getmaxx(); i++)
  {k=i%15;
  setcolor(k);
  line(0, i, getmaxx()/2 ,getmaxy()/2);
  line(i, 0, getmaxx()/2, getmaxy()/2);
  line(getmaxx()-i, getmaxy(), getmaxx()/2, getmaxy()/2);
  line(getmaxx(), getmaxy()-i, getmaxx()/2, getmaxy()/2);}

 bar (getmaxx()/2-50, getmaxy()/2-50, getmaxx()/2+50, getmaxy()/2+50);
 int  poly[8]={(getmaxx()/2)-150, (getmaxy()/2)-150, (getmaxx()/2)-150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)-150};
 int poly4[8]={getmaxx()-150, 200, getmaxx(), 200, getmaxx(), 300, getmaxx()-150, 300};
 int poly5[8]={getmaxx()-160, 350, getmaxx(), 350, getmaxx(), 405, getmaxx()-160, 405};
 setfillstyle( SOLID_FILL, 0);
 fillpoly (4, poly5);
 fillpoly (4, poly);
 fillpoly (4, poly4);
 outtextxy(getmaxx()-120, 225, "Enter the code");
 outtextxy(getmaxx()-120, 235, "of the shooter");
 outtextxy(getmaxx()-135, 245, "1. DRONE");
 outtextxy(getmaxx()-135, 255, "2. UFO ");
 outtextxy(getmaxx()-135, 265, "3. TANK");
 outtextxy(getmaxx()-135, 275, "4. FIGHTER JET");
 outtextxy(getmaxx()-150, 360, "Choose the shooter");
 outtextxy(getmaxx()-150, 370, "and press any");
 outtextxy(getmaxx()-150, 380, "other button to");
 outtextxy(getmaxx()-150, 390, "select and leave.");
 settextstyle(6, 0, 4);
 outtextxy(getmaxx()/2-50, getmaxy()/2-150, "DRONE");
 settextstyle(1, 0, 5);
 setcolor(7);
 for( i=0; i<100; i++)
  {outtextxy(getmaxx()/2-10,getmaxy()/2+30-i, "S"); }
   outtextxy(getmaxx()/2, getmaxy()/2-20, "---");
   outtextxy(getmaxx()/2-78, getmaxy()/2-20, "---");
   outtextxy(getmaxx()/2-83, getmaxy()/2-20, "I");
   outtextxy(getmaxx()/2+73, getmaxy()/2-20, "I");
   back:
   shoot=getch();
     if(shoot=='1')
      {     transition();
	    settextstyle(6, 0, 4);
	    outtextxy(getmaxx()/2-50, getmaxy()/2-150, "DRONE");
	    settextstyle(1, 0, 5);
	    setcolor(7);
	    for( i=0; i<100; i++)
	    {outtextxy(getmaxx()/2-10,getmaxy()/2+30-i, "S"); }
	    outtextxy(getmaxx()/2, getmaxy()/2-20, "---");
	    outtextxy(getmaxx()/2-78, getmaxy()/2-20, "---");
	    outtextxy(getmaxx()/2-83, getmaxy()/2-20, "I");
	    outtextxy(getmaxx()/2+73, getmaxy()/2-20, "I");
	    disp=1;
	    goto back;

	    }
  else if(shoot=='2')
  {         transition();
	    settextstyle(6, 0, 4);
	    outtextxy(getmaxx()/2-25, getmaxy()/2-140, "UFO");
	    for(i=0; i<=20; i++)
	      { setcolor(7);
	      circle(getmaxx()/2, getmaxy()/2, i);}
	    for(i=30; i<=60; i++)
	      { setcolor(7);
	      circle(getmaxx()/2, getmaxy()/2, i);}
	    disp=2;
	    goto back;
	    }

   else if (shoot=='3')
   {        transition();
	    settextstyle(6, 0, 4);
	    outtextxy(getmaxx()/2-37, getmaxy()/2-150, "TANK");

	    int  poly1[8]={(getmaxx()/2)-40, (getmaxy()/2)-65, (getmaxx()/2)-40, (getmaxy()/2)+65, (getmaxx()/2)+40, (getmaxy()/2)+65, (getmaxx()/2)+40, (getmaxy()/2)-65};
	    setfillstyle( SOLID_FILL, 2);
	    fillpoly (4, poly1);
	    for(i=15; i<25;i++)
	      { setcolor(0);
	      circle(getmaxx()/2, getmaxy()/2+10, i);}
	    for(i=-3; i<=2;i++)
	      line(getmaxx()/2+i, getmaxy()/2-5, getmaxx()/2+i, getmaxy()/2-60);
	    setcolor(15);
	    disp=3;
	    goto back;
	  }

   else if(shoot=='4')
   {         transition();
	     settextstyle(6, 0, 4);
	     outtextxy(getmaxx()/2-70, getmaxy()/2-150, "FIGHTER JET");
	     int poly2[6]={getmaxx()/2, getmaxy()/2-85, getmaxx()/2-75, getmaxy()/2+100, getmaxx()/2+75, getmaxy()/2+100};
	     setfillstyle( SOLID_FILL, 2);
	     fillpoly(3, poly2);
	     setfillstyle(SOLID_FILL, 0);
	     fillellipse(getmaxx()/2, getmaxy()/2+40, 35, 35);
	     int poly3[6]={getmaxx()/2, getmaxy()/2+25, getmaxx()/2-25, getmaxy()/2+120, getmaxx()/2+25, getmaxy()/2+120};
	     fillpoly(3, poly3);
	     setcolor(0);
	     for(i=0; i<=35; i++)
	       {circle(getmaxx()/2, getmaxy()/2+40, i);}
	     for(i=0; i<25; i++)
	       {line(getmaxx()/2-75, getmaxy()/2+100+i, getmaxx()/2+75, getmaxy()/2+100+i);}
	     disp=4;
	     setcolor(15);
	     goto back;	 }

   else
     {closegraph();
     closegraph();
     return(0); }
     }


char *nameinput()
{  char *highname;
   closegraph();
   int gd= DETECT, gm;
   initgraph(&gd, &gm, "");
   setbkcolor(6);
   outtextxy(250, 250, "Enter player name");
   gotoxy(40, 20);
   cin>>highname;
   closegraph();
   return(highname);
}



void highscore()
{ char inp;
  if(newscore!=0)
  {reset();}
  int k;
  closegraph();
  int gd= DETECT, gm;
  initgraph(&gd, &gm, "");
  cleardevice();
  for(int i=0; i<=getmaxx(); i++)
   {k=i%15;
   setcolor(k);
   line(i,0 ,i ,getmaxy());}
  int  poly[8]={(getmaxx()/2)-150, (getmaxy()/2)-150, (getmaxx()/2)-150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)+150, (getmaxx()/2)+150, (getmaxy()/2)-150};
  setfillstyle( SOLID_FILL, 0);
  fillpoly (4, poly);
  int j;
  for( j=0, i=0; j<=250; j+=10, i++)
   { delay(70);
   setcolor(1+i%7);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)-145,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)-145);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)-144,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)-145);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)-143,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)-145);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)-142,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)-145);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)+145,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)+145);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)+145,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)+144);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)+145,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)+143);
   line((getmaxx()/2)-145+j+i, (getmaxy()/2)+145,(getmaxx()/2)-145+j+10+i, (getmaxy()/2)+142);

   line((getmaxx()/2)-145, (getmaxy()/2)-145+j+i,(getmaxx()/2)-145, (getmaxy()/2)-145+j+10+i);
   line((getmaxx()/2)-144, (getmaxy()/2)-145+i+j,(getmaxx()/2)-145, (getmaxy()/2)-145+i+j+10);
   line((getmaxx()/2)-143, (getmaxy()/2)-145+j+i,(getmaxx()/2)-145, (getmaxy()/2)-145+j+10+i);
   line((getmaxx()/2)-142, (getmaxy()/2)-145+i+j,(getmaxx()/2)-145, (getmaxy()/2)-145+j+10+i);
   line((getmaxx()/2)+145, (getmaxy()/2)-145+j+i,(getmaxx()/2)+145, (getmaxy()/2)-145+j+10+i);
   line((getmaxx()/2)+145, (getmaxy()/2)-145+i+j,(getmaxx()/2)+144, (getmaxy()/2)-145+i+j+10);
   line((getmaxx()/2)+145, (getmaxy()/2)-145+j+i,(getmaxx()/2)+143, (getmaxy()/2)-145+j+10+i);
   line((getmaxx()/2)+145, (getmaxy()/2)-145+i+j,(getmaxx()/2)+142, (getmaxy()/2)-145+j+10+i);
   }
  setcolor(15);
  settextstyle( 3, 0, 4);
  outtextxy((getmaxx()/2)-80, (getmaxy()/2)-130, "HIGH SCORE");
  settextstyle( 3, 0, 1);
  setcolor(6);
  char score[5], score2[5], score3[5], score4[5], score5[5];
  itoa(hgscr[0].highscr, score, 10);
  itoa(hgscr[1].highscr, score2, 10);
  itoa(hgscr[2].highscr, score3, 10);
  itoa(hgscr[3].highscr, score4, 10);
  itoa(hgscr[4].highscr, score5, 10);
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)-90, "Name");
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)-90, "Score");
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)-50, hgscr[0].name);
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)-50, score );
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)-20, hgscr[1].name);
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)-20, score2);
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)+10, hgscr[2].name);
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)+10, score3);
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)+40, hgscr[3].name);
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)+40, score4);
  outtextxy((getmaxx()/2)-100, (getmaxy()/2)+70, hgscr[4].name);
  outtextxy((getmaxx()/2)+30, (getmaxy()/2)+70, score5);

  int  poly2[8]= {(getmaxx()/2)+150, (getmaxy()/2)+180, getmaxx(), (getmaxy()/2)+180, getmaxx(), (getmaxy()/2)+220, (getmaxx()/2)+150, (getmaxy()/2)+220};
  setfillstyle( SOLID_FILL, 0);
  fillpoly (4, poly2);
  settextstyle( 2, 0, 4);
  setcolor(15);
  outtextxy((getmaxx()/2)+155, (getmaxy()/2)+190, "Press 'r' to reset scores");
  outtextxy((getmaxx()/2)+155, (getmaxy()/2)+200, "Press any other key to exit");

 inp=getch();
 if(inp=='r'||inp=='R')
 { highreset();}
  closegraph();
  closegraph();
}




void reset()
{char name4[20];
int spec, score;
for(int i=0; i<5;i++)
{
  hgscr2[i]=hgscr[i];
  for(spec=0; spec<i;spec++)
  {
    if(hgscr2[i].highscr>hgscr2[spec].highscr)
    {
    sid=hgscr2[spec];
    hgscr2[spec]=hgscr2[i];
    hgscr2[i]=sid;
    }
   }
}

strcpy(name4, newname);
score= newscore;
if (score>hgscr2[4].highscr)
{
strcpy(hgscr2[4].name, name4);
hgscr2[4].highscr=score;
}
for(i=0; i<5;i++)
{
  hgscr[i]=hgscr2[i];
  for(spec=0; spec<i;spec++)
  {
    if(hgscr[i].highscr>hgscr[spec].highscr)
    {
    sid=hgscr[spec];
    hgscr[spec]=hgscr[i];
    hgscr[i]=sid;
    }
   }
}
fstream fout;
fout.open("highscore.dat", ios::out | ios::binary);
for(i=0; i<5; i++)
{fout.write((char*)&hgscr[i], sizeof(hgscr[i]));}
fout.close();
}


void highreset()
{
fstream res;
strcpy(reseter.name, "No Data");
reseter.highscr=0;
res.open("highscore.dat", ios::out | ios::binary);
for(int i=0; i<5;i++)
{res.write((char*)&reseter, sizeof(reseter));}
res.close();
fstream res2;
res2.open("highscore.dat", ios::in | ios::binary);
for(i=0; i<5;i++)
{res2.read((char*)&hgscr[i], sizeof(hgscr[i]));}
res2.close();
highscore();
}
