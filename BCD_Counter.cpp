#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

struct FlipFlop
{
    bool S,R,Q;
};
bool clockEdge;
int counter = 0;
FlipFlop flp[4];
vector<pair<int,int> >stats;

pair<int,int> drawFlipFlop(int c_x,int c_y)
{
    int width = 100;
    int height = 150;
    int topLeftx = c_x-width/2;
    int topLefty = c_y-height/2;
    int bottomRightx = c_x+width/2;
    int bottomRighty = c_y+height/2;
    rectangle(topLeftx,topLefty,bottomRightx,bottomRighty);
    int sx = topLeftx + 10;
    int sy = topLefty + 10;
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(sx,sy,"S");
    int rx = topLeftx + 10;
    int ry = topLefty + height - 36;
    outtextxy(rx,ry,"R");
    int qx = topLeftx + width - 27;
    int qy = topLefty + 10;
    outtextxy(qx,qy,"Q");
    int qbarx = topLeftx + width - 27;
    int qbary = topLefty + height - 34;
    line(qbarx,qbary-1,qbarx+20,qbary-1);
    outtextxy(qbarx,qbary,"Q");
    int clrx = rx;
    int clry = (sy+ry)/2;
    clry += 8;
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(clrx,clry,"CLK");
    pair<int,int>  qcor = make_pair(qx,qy);
    return qcor;
}

void drawAndGate(int c_x,int c_y)
{
    int width,height;
    width = height = 24;
    line(c_x-width/2,c_y-height/2,c_x-width/2,c_y+height/2);
    line(c_x-width/2,c_y-height/2,c_x+width/2-1,c_y-height/2);
    line(c_x-width/2,c_y+height/2,c_x+width/2,c_y+height/2);
    arc(c_x+width/2,c_y,-90,100,height/2);
}

void drawCircuit()
{
	pair<int,int> qcor1 = drawFlipFlop(250,300);
	drawAndGate(75,250);
	drawAndGate(75,350);

	pair<int,int> qcor2 = drawFlipFlop(550,300);
    drawAndGate(qcor1.first+100,qcor1.second+15);
    drawAndGate(qcor1.first+100,qcor1.second+115);

	pair<int,int> qcor3 = drawFlipFlop(850,300);
	drawAndGate(qcor2.first+140,qcor2.second+15);
	drawAndGate(qcor2.first+140,qcor2.second+115);

	pair<int,int> qcor4 = drawFlipFlop(1150,300);

	setfillstyle(SOLID_FILL,BLACK);
	line(15,450,1050,450);
	line(1050,450,1050,300);
	fillellipse(1050,450,3,3);
    line(1050,300,1100,300);
    line(750,450,750,300);
    fillellipse(750,450,3,3);
    line(750,300,800,300);
    line(450,450,450,300);
    fillellipse(450,450,3,3);
    line(450,300,500,300);
    line(150,450,150,300);
    fillellipse(150,450,3,3);
    line(150,300,200,300);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
    outtextxy(5,440,"CLK");
    rectangle(5,440,40,460);

    setfillstyle(SOLID_FILL,WHITE);
	fillellipse(1095,300,5,5);
	fillellipse(795,300,5,5);
	fillellipse(495,300,5,5);
	fillellipse(195,300,5,5);

    //Output of Gates
    line(99,250,200,250);
    line(99,350,200,350);
    line(qcor1.first+124,qcor1.second+15,500,qcor1.second+15);
    line(qcor1.first+124,qcor1.second+115,500,qcor1.second+115);
    line(qcor2.first+164,qcor2.second+15,800,qcor2.second+15);
    line(qcor2.first+164,qcor2.second+115,800,qcor2.second+115);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,3);
    outtextxy(10,530,"CLK");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
    char s[1];
    s[0] = counter + '0';
    s[1] = '\0';
    outtextxy(95,509,s);
    line(70,553,90,553);
    line(90,553,90,534);
    line(90,534,110,534);
    stats.push_back(make_pair(110,534));
    clockEdge = false;
    outtextxy(10,560,"Q3");
    line(70,583,110,583);
    stats.push_back(make_pair(110,583));
    outtextxy(10,590,"Q2");
    line(70,608,110,608);
    stats.push_back(make_pair(110,608));
    outtextxy(10,620,"Q1");
    line(70,633,110,633);
    stats.push_back(make_pair(110,633));
    outtextxy(10,650,"Q0");
    line(70,658,110,658);
    stats.push_back(make_pair(110,658));

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    line(320,qcor1.second+8,320,50);
    line(320,qcor1.second+8,300,qcor1.second+8);
    outtextxy(300,40,"Q3");
    line(320,qcor2.second - 58,20,qcor2.second-58);
    line(20,355,20,qcor2.second-58);
    line(20,355,63,355);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(320,qcor2.second - 58,3,3);

    line(620,qcor2.second+8,620,50);
    line(620,qcor2.second+8,600,qcor2.second+8);
    outtextxy(600,40,"Q2");
    line(620,qcor2.second - 28,50,qcor2.second-28);
    line(50,240,50,qcor2.second-28);
    line(50,240,63,240);
    line(qcor1.first+55,qcor2.second - 28,qcor1.first+55,qcor1.second+125);
    line(qcor1.first+55,qcor1.second +125,qcor1.first+86,qcor1.second+125);
	fillellipse(620,qcor2.second - 28,3,3);
    fillellipse(qcor1.first+55,qcor2.second - 28,3,3);

    line(920,qcor3.second+8,920,50);
    line(920,qcor3.second+8,900,qcor3.second+8);
    outtextxy(900,40,"Q1");
    line(920,qcor2.second - 38,40,qcor2.second-38);
    line(40,250,40,qcor2.second-38);
    line(qcor1.first+75,qcor1.second+5,qcor1.first+75,qcor2.second-38);
    line(qcor1.first+75,qcor1.second+5,qcor1.first+86,qcor1.second+5);
    line(qcor1.first+75,qcor1.second+5,qcor1.first+75,qcor1.second+105);
    line(qcor1.first+75,qcor1.second+105,qcor1.first+86,qcor1.second+105);
    line(qcor2.first+110,qcor2.second+110,qcor2.first+128,qcor2.second+110);
    line(qcor2.first+110,qcor2.second+110,qcor2.first+110,qcor2.second-38);
    line(40,250,63,250);
	fillellipse(920,qcor2.second - 38,3,3);
	fillellipse(qcor1.first+75,qcor2.second-38,3,3);
	fillellipse(qcor2.first+110,qcor2.second-38,3,3);

    line(1200,qcor4.second+8,1220,qcor4.second+8);
    line(1220,qcor4.second+8,1220,50);
    outtextxy(1200,40,"Q0");
    line(1220,qcor2.second - 48,30,qcor2.second-48);
    line(30,260,30,qcor2.second-48);
    line(30,260,63,260);
    line(qcor1.first+65,qcor1.second+15,qcor1.first+65,qcor2.second-48);
    line(qcor1.first+65,qcor1.second+15,qcor1.first+86,qcor1.second+15);
    line(qcor1.first+65,qcor1.second+15,qcor1.first+65,qcor1.second+115);
    line(qcor1.first+65,qcor1.second+115,qcor1.first+86,qcor1.second+115);
    line(980,qcor4.second+108,980,qcor4.second-48);
    line(980,qcor4.second+108,1100,qcor4.second+108);
    line(qcor2.first+100,qcor2.second+120,qcor2.first+128,qcor2.second+120);
    line(qcor2.first+100,qcor2.second+120,qcor2.first+100,qcor2.second-48);
    line(qcor2.first+100,qcor2.second+15,qcor2.first+128,qcor2.second+15);
    line(qcor2.first+100,qcor2.second+15,qcor2.first+128,qcor2.second+15);
	fillellipse(1220,qcor2.second - 48,3,3);
	fillellipse(qcor1.first+65,qcor2.second-48,3,3);
	fillellipse(980,qcor2.second-48,3,3);
	fillellipse(qcor2.first+100,qcor2.second-48,3,3);
    fillellipse(qcor2.first+100,qcor2.second+15,3,3);

    line(310,qcor1.second+108,310,qcor1.second+190);
    line(310,qcor1.second+108,300,qcor1.second+108);
    line(qcor2.first+80,qcor2.second+5,qcor2.first+128,qcor2.second+5);
    line(qcor2.first+80,qcor2.second+190,qcor2.first+80,qcor2.second+5);
    line(310,qcor2.second+190,qcor2.first+80,qcor2.second+190);

    line(620,qcor2.second+108,620,qcor2.second+178);
    line(620,qcor2.second+108,600,qcor2.second+108);
    line(620,qcor2.second+178,qcor1.first+45,qcor2.second+178);
    line(qcor1.first+45,qcor2.second+178,qcor1.first+45,qcor2.second+25);
    line(qcor1.first+45,qcor2.second+25,qcor1.first+86,qcor2.second+25);

    line(920,qcor3.second+108,920,qcor3.second+178);
    line(920,qcor3.second+108,900,qcor3.second+108);
    line(qcor2.first+90,qcor2.second+25,qcor2.first+128,qcor2.second+25);
    line(qcor2.first+90,qcor2.second+25,qcor2.first+90,qcor2.second+178);
    line(qcor2.first+90,qcor2.second+178,920,qcor2.second+178);

    line(1220,qcor4.second+108,1220,qcor4.second+178);
    line(1220,qcor4.second+108,1200,qcor4.second+108);
    line(1220,qcor4.second+178,1000,qcor4.second+178);
    line(1000,qcor4.second+178,1000,qcor4.second+8);
    line(1000,qcor4.second+8,1100,qcor4.second+8);

    //Connections
    line(30,260,30,345);
	fillellipse(30,260,3,3);
    line(30,345,63,345);
}

void init()
{
    for(int i = 0 ; i < 4 ; i++)
        flp[i].Q = false;
    flp[0].S = true;
    flp[0].R = false;
}

void onclock()
{
    setcolor(BLACK);
    if(!clockEdge)
    {
        counter = (counter + 1)%10;
        bool q[4];
        for(int i = 0 ; i < 4 ; i++)
            q[i] = flp[i].Q;

        flp[0].Q = ((!q[0] && (!q[0])) | (!(q[0])&&(q[0])));
        flp[1].Q = ((((q[0]) && (!q[3]) && (!q[1]) && !((q[1]) && (q[0]))) && (!q[1])) | (!((q[0]) && (q[1])) && (q[1])));
        flp[2].Q = ((((q[1]) && (q[0]) && (!q[2]) && !((q[2]) && (q[1]) && (q[0]))) && (!q[2])) | (!((q[2]) && (q[1]) && (q[0])) &&(q[2])));
        flp[3].Q = ((q[2] && q[1] && q[0] && !(q[0] && q[3])) && (!q[3])) | ((!(q[0] && q[3])) && (q[3]));
        for(int i = 3 ; i >= 0 ; i--)
            cout << flp[i].Q << " ";
        line(stats[0].first,stats[0].second,stats[0].first,stats[0].second+19);
        stats[0].second += 19;
        clockEdge = true;
    }
    else
    {
        line(stats[0].first,stats[0].second,stats[0].first+20,stats[0].second);
        stats[0].first += 20;
        line(stats[0].first,stats[0].second,stats[0].first,stats[0].second-19);
        stats[0].second -= 19;
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
        char s[1];
        s[0] = counter + '0';
        s[1] = '\0';
        outtextxy(stats[0].first+5,stats[0].second-25,s);
        line(stats[0].first,stats[0].second,stats[0].first+20,stats[0].second);
        stats[0].first += 20;
        clockEdge = false;
    }

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    setfillstyle(SOLID_FILL,GREEN);
    if(flp[3].Q)
    {
        bar(stats[1].first,stats[1].second-19,stats[1].first+20,stats[1].second+1);
        stats[1].first += 20;
        setcolor(YELLOW);
    }
    else
    {
        setcolor(BLACK);
        line(stats[1].first,stats[1].second,stats[1].first+20,stats[1].second);
        stats[1].first += 20;
    }

    outtextxy(300,40,"Q3");
    if(flp[2].Q)
    {
        bar(stats[2].first,stats[2].second-19,stats[2].first+20,stats[2].second+1);
        stats[2].first += 20;
        setcolor(YELLOW);
    }
    else
    {
        setcolor(BLACK);
        line(stats[2].first,stats[2].second,stats[2].first+20,stats[2].second);
        stats[2].first += 20;
    }

    outtextxy(600,40,"Q2");
    if(flp[1].Q)
    {
        bar(stats[3].first,stats[3].second-19,stats[3].first+20,stats[3].second+1);
        stats[3].first += 20;
        setcolor(YELLOW);
    }
    else
    {
        setcolor(BLACK);
        line(stats[3].first,stats[3].second,stats[3].first+20,stats[3].second);
        stats[3].first += 20;
    }

    outtextxy(900,40,"Q1");
    if(flp[0].Q)
    {
        bar(stats[4].first,stats[4].second-19,stats[4].first+20,stats[4].second+1);
        stats[4].first += 20;
        setcolor(YELLOW);
    }
    else
    {
        setcolor(BLACK);
        line(stats[4].first,stats[4].second,stats[4].first+20,stats[4].second);
        stats[4].first += 20;
    }

    outtextxy(1200,40,"Q0");
    cout << endl;
}

void addMouseListener()
{
    while(1)
    {
        int xcor = mousex();
        int ycor = mousey();
        delay(50);
        if(ismouseclick(WM_LBUTTONUP) && (xcor>=5 && xcor<=40 && ycor>=440 && ycor<=460))
            onclock();
        clearmouseclick(WM_LBUTTONUP);
    }
}

int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "BGI");
    setfillstyle(1,15);
    floodfill(getmaxx()/2,getmaxy()/2,15);
    settextstyle(10,0,4);
    setbkcolor(15);
    setcolor(0);
    outtextxy(400,10,"SYNCHRONOUS BCD COUNTER");
    drawCircuit();
    init();
    addMouseListener();
    closegraph();
}

