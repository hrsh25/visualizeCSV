#include<iostream>
#include <cstdio>
#include <conio.h>
#include<fstream>
#include <graphics.h>
#include<iomanip>
using namespace std;
/*static variable declarations*/
static int u1[2][2] = {{120,628},{200,628}};
static int v1[2][2] = {{120,628},{200,628}};
class Graph                 //Base Class
{
public:
    char str[64];
    int gdriver = DETECT, gmode, err;
    int midx;
    int midy;
    int tmp1;
    int tmp2;
    int max_x = 2000;
    int max_y = 700;
    char depart[20][100];
    virtual int graph_Initial(){}           //Denotes virtual function-1 Definition
    virtual void draw_bar(double arr){}     //Denotes virtual function-1 Definition
};
class Student_City: public Graph            //Derived Class 1
{
public:
    int graph_Initial()
    {
        initwindow(max_x,max_y,"CITY GRAPH");

        err = graphresult();

    if (err != grOk) {
        /* error occurred */
        cout<<"Graphics Error: "<<grapherrormsg(err);
        return 0;
        }

        /* mid position in x and y axis */
        midx = max_x / 2;
        midy = max_y / 2;

        /* line at y and x-axis */
        line(100, 0, 100, max_y);
        line(100, max_y-70 ,max_x,max_y-70);

        /* units at y-axis */
        for (int i = 0; i < 11; i++) {
                sprintf(str, "%d", i*10);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                moveto(50, max_y - 65 - i * 60);
                outtext(str);
        }

        /* y-axis represents revenue */
        moveto(20, midy);
        settextstyle(TRIPLEX_FONT, VERT_DIR, 2);
        sprintf(str, "%s", "NUMBER OF STUDENTS");
        outtext(str);

        /* x-axis represent departments */
        moveto(650,685);
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
        sprintf(str, "%s", "CITY");
        outtext(str);

        tmp1 = max_y - 40;
        tmp2 = 160;
        }
        void draw_bar(double arr)
        {
                    setcolor(BLUE);
            for (int i = 0; i < arr*5; i++) {
                            line(v1[0][0], v1[0][1], v1[1][0], v1[1][1]);
                            v1[0][1] -= 1;
                            v1[1][1] -= 1;
                            delay(10);
                }
                v1[0][0] += 115;
                v1[0][1] = max_y - 72;
                v1[1][1] = max_y - 72;
                v1[1][0] += 115;
        }
        void draw_3dbar(double arr)
        {
                setfillstyle(LINE_FILL,RED);
                bar3d(v1[0][0],arr*50,v1[1][0],v1[0][1],30,5);
                v1[0][1] = v1[0][1] - 1;
                v1[1][1] = v1[1][1] - 1;
                v1[0][0] += 115;
                v1[0][1] = max_y - 72;
                v1[1][1] = max_y - 72;
                v1[1][0] += 115;
        }
};
class Student_SGPA: public Graph                //Derived Class 2
{
public:
    int graph_Initial()
    {
        initwindow(max_x,max_y,"Student Result Report");

        err = graphresult();

    if (err != grOk) {
        /* error occurred */
        cout<<"Graphics Error: "<<grapherrormsg(err);
        return 0;
        }

        /* mid position in x and y axis */
        midx = max_x / 2;
        midy = max_y / 2;

        /* line at y and x-axis */
        line(100, 0, 100, max_y);
        line(100, max_y-70 ,max_x,max_y-70);

        /* units at y-axis */
        for (int i = 0; i < 11; i++) {
                sprintf(str, "%d", i);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                moveto(50, max_y - 65 - i * 60);
                outtext(str);
        }

        /* y-axis represents revenue */
        moveto(20, midy);
        settextstyle(TRIPLEX_FONT, VERT_DIR, 2);
        sprintf(str, "%s", "SGPA");
        outtext(str);

        /* x-axis represent departments */
        moveto(650,685);
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
        sprintf(str, "%s", "NAME");
        outtext(str);

        tmp1 = max_y - 40;
        tmp2 = 160;
        }
        void draw_bar(double arr)
        {
                    setcolor(YELLOW);
            for (int i = 0; i < arr*60; i++) {
                            line(u1[0][0], u1[0][1], u1[1][0], u1[1][1]);
                            u1[0][1] = u1[0][1] - 1;
                            u1[1][1] = u1[1][1] - 1;
                            delay(10);
                }
                u1[0][0] += 115;
                u1[0][1] = max_y - 72;
                u1[1][1] = max_y - 72;
                u1[1][0] += 115;
        }
        void draw_3dbar(double arr=0)
        {
                setfillstyle(LINE_FILL,BLUE);
                bar3d(u1[0][0],arr*60,u1[1][0],u1[0][1],30,5);
                u1[0][1] = u1[0][1] - 1;
                u1[1][1] = u1[1][1] - 1;
                u1[0][0] += 115;
                u1[0][1] = max_y - 72;
                u1[1][1] = max_y - 72;
                u1[1][0] += 115;
        }
};
int main() {
    fstream ifs;
    char ch;
    int cnt = 0;
    int choice;
    int i = 0;
    int j = 0;
    int array[20];
    double sgpa;
    string name;
    string SGPA;
    Student_SGPA ssobj;
    Student_City scobj;
    for(int p=0;p<120;p++)
        cout<<"*";
    cout<<"\n\t\t\t\t\tWELCOME TO OUR CSV READER APPLICATION\n";
    cout<<endl;
    for(int p=0;p<120;p++)
        cout<<"*";
    while(1)
    {
        cout<<"\n\t\t\t\t1.DATA FOR SGPA SURVEY.";
        cout<<"\n\t\t\t\t2.DATA FOR CITY SURVEY.";
        cout<<"\n\t\t\t\t3.EXIT.";
        cout<<"\n\t\t\t\tENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                ifs.open("F:\\New folder\\SGP-1\\Result.csv",ios::in);
                ifs.seekg(0);
                cout<<"\n\t\t\t\t1. VIEW YOUR DATA.";
                cout<<"\n\t\t\t\t2. ADD NEW DATA.";
                cout<<"\n\t\t\t\t3. SEARCH BY NAME.";
                cout<<"\n\t\t\t\t4. VIEW GRAPH.";
                cout<<"\n\t\t\t\t5. DRAW 3-d GRAPH.";
                cout<<"\n\t\t\t\t6. EXIT.";
                cout<<"\n\t\t\t\tENTER YOUR CHOICE : ";
                cin>>choice;
                switch(choice)
                {
                case 1:
                    {
                        ifs.seekg(0,ios::beg);
                        if (ifs.is_open())
                        {
                            while (ifs.good())
                            {
                                getline(ifs,name, ',');
                                getline(ifs,SGPA,'\n');
                                cout<<name<<" "<<SGPA<<endl;
                            }
                            ifs.close();
                        }
                        else
                        {
                            cout << "Error opening file";
                        }
                        break;
                    }
                case 2:
                    {
                        if (ifs.is_open())
                        {
                            cout<<"ENTER NAME: ";
                            cin>>name;
                            cout<<"Enter SGPA :";
                            cin>>sgpa;
                            ifs.open("F:\\New folder\\SGP-1\\Result.csv",ios::app);
                            ifs<<endl<<name<<","<<sgpa;
                            ifs.close();
                        }
                        else
                        {
                            cout << "Error opening file";
                        }
                    break;
                    }
                case 3:
                    {
                        fstream sfs;
                        sfs.open("F:\\New folder\\SGP-1\\Result.csv",ios::in);
                        if (sfs.is_open())
                        {
                            string temp;
                            int flag;
                            cout<<"Enter a name:";
                            cin>>temp;
                            while (sfs.good())
                            {
                                getline(sfs,name,',');
                                getline(sfs,SGPA,'\n');
                                if(name == temp)
                                {
                                    flag = 1;
                                    break;
                                }
                            }
                            if(flag)
                                cout<<"Name Found";
                            else
                                cout<<"Name not found";
                            sfs.close();
                        }
                        else
                        {
                            cout << "Error opening file";
                        }
                        break;
                    }
                case 4:
                    {
                        ssobj.graph_Initial();
                        if (ifs.is_open())
                            {
                                while (ifs.good())
                                    {
                                        getline(ifs,name,',');
                                        getline(ifs,SGPA,'\n');
                                        strcpy(ssobj.depart[i],name.c_str());
                                        setcolor(WHITE);
                                        outtextxy(ssobj.tmp2,ssobj.tmp1,ssobj.depart[i]);
                                        ssobj.tmp2 = ssobj.tmp2 + 120;
                                        sgpa= atof(SGPA.c_str());
                                        ssobj.draw_bar(sgpa);
                                    }
                            ifs.close();
                            }
                        else
                        {
                            cout << "Error opening file";
                        }
                    break;
                    }
                case 5:
                    {
                        ssobj.graph_Initial();
                        if (ifs.is_open())
                        {
                                while (ifs.good())
                                {
                                    getline(ifs,name,',');
                                    getline(ifs,SGPA,'\n');
                                    strcpy(ssobj.depart[i],name.c_str());
                                    setcolor(WHITE);
                                    outtextxy(ssobj.tmp2,ssobj.tmp1,ssobj.depart[i]);
                                    ssobj.tmp2 = ssobj.tmp2 + 120;
                                    sgpa= atof(SGPA.c_str());
                                    ssobj.draw_3dbar(sgpa);
                                }
                            ifs.close();
                        }
                        else
                        {
                            cout << "Error opening file";
                        }
                    break;
                    }
                case 6:
                    {
                        exit(0);
                    }
                default:
                    cout<<"Wrong input chosen";
            }
            break;
            }
        case 2:
            {
                ifs.open("F:\\New folder\\SGP-1\\City.csv",ios::in);
                ifs.seekg(0);
                cout<<"\n\t\t\t\t1. VIEW GRAPH.";
                cout<<"\n\t\t\t\t2. DRAW 3-d GRAPH.";
                cout<<"\n\t\t\t\t3. EXIT.";
                cout<<"\n\t\t\t\tENTER YOUR CHOICE : ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        scobj.graph_Initial();
                        if (ifs.is_open())
                            {
                                while (ifs.good())
                                    {
                                            getline(ifs,name,',');
                                            getline(ifs,SGPA,'\n');
                                            strcpy(scobj.depart[i],name.c_str());
                                            setcolor(WHITE);
                                            outtextxy(scobj.tmp2,scobj.tmp1,scobj.depart[i]);
                                            scobj.tmp2 = scobj.tmp2 + 120;
                                            sgpa= atof(SGPA.c_str());
                                            scobj.draw_bar(sgpa);
                                    }
                            ifs.close();
                            }
                        else
                        {
                            cout << "Error opening file";
                        }
                    break;
                    }
                case 2:
                    {
                        scobj.graph_Initial();
                        if (ifs.is_open())
                        {
                                while (ifs.good())
                                {
                                    getline(ifs,name,',');
                                    getline(ifs,SGPA,'\n');
                                    strcpy(scobj.depart[i],name.c_str());
                                    setcolor(WHITE);
                                    outtextxy(scobj.tmp2,scobj.tmp1,scobj.depart[i]);
                                    scobj.tmp2 = scobj.tmp2 + 120;
                                    sgpa= atof(SGPA.c_str());
                                    scobj.draw_3dbar(sgpa);
                                }
                                getch();
        /* deallocate memory allocated for graphic screen */
                                    closegraph();
                            ifs.close();
                        }
                        else
                        {
                            cout << "Error opening file";
                        }
                    break;
                    }
                case 3:
                        {
                            exit(0);
                        }
                default:
                    cout<<"Wrong input chosen";
                }
                break;
            }
        case 3:
                {
                    exit(0);
                }
        default:
            cout<<"Wrong input chosen";
    }
}
        getch();
        /* deallocate memory allocated for graphic screen */
        closegraph();
        ifs.close();
        return 0;
}
