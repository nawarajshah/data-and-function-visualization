#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<string.h>

// Defining a function for sin and cos
void mathFunction();
void singraph();
void cosgraph();

// Defining a function for recursive
void recursiveFunction();
void fact();

//Defining a function for data relation
void dataFunction();
void pieChart();
void barDiagram();

// Main function
void main() {
	int choiceIndex;
	clrscr();
	repeat:
		printf("Make your choice:\n");
		printf("1. Math function\n");
		printf("2. Recursive function\n");
		printf("3. Data relation\n");
		printf("Or press zero \"0\" to terminate\n");
		scanf("%d",&choiceIndex);
		if(choiceIndex==0)
			goto end;
		switch(choiceIndex) {
			case 1:
				mathFunction();
				break;
			case 2:
				recursiveFunction();
				break;
			case 3:
				dataFunction();
				break;
		}
		goto repeat;
	end:
	clrscr();
}

// Math function menu
void mathFunction() {
	int graphno;
	clrscr();
	repeat:
		printf("Make your choice:\n");
		printf("1. Sin function\n");
		printf("2. Cos function\n");
		printf("Or press zero \"0\" to go back\n");
		scanf("%d",&graphno);
		if(graphno==0)
			goto end;
		switch(graphno) {
			case 1:
				singraph();
				break;
			case 2:
				cosgraph();
				break;
		}
		goto repeat;
	end:
	clrscr();
}

// Recursive function menu
void recursiveFunction() {
	int recursiveNo;
	clrscr();
	repeat:
		printf("Make your choice:\n");
		printf("1. Factorial function\n");
		printf("Or press zero \"0\" to go back\n");
		scanf("%d",&recursiveNo);
		if(recursiveNo==0)
			goto end;
		switch(recursiveNo) {
			case 1:
				fact();
				break;
		}
		goto repeat;
	end:
	clrscr();
}

// Data relation menu
void dataFunction() {
	int datano;
	clrscr();
	repeat:
		printf("Make your choice:\n");
		printf("1. Pie chart\n");
		printf("2. Bar diagram\n");
		printf("Or press zero \"0\" to go back\n");
		scanf("%d",&datano);
		if(datano==0)
			goto end;
		switch(datano) {
			case 1:
				pieChart();
				break;
			case 2:
				barDiagram();
				break;
		}
		goto repeat;
	end:
	clrscr();
}

void fact() {
	int gd=DETECT,gm;
	int i,j,k,l=2,n,midx,midy;
	long int fact=1,Pfact;
	char factInfo[20],buff[10];
	clrscr();

	printf("Enter any number:\n");
	scanf("%d",&n);

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	if(n>1) {
		i=n;
		j=1;

		// For forward flow
		while(i>1 && getchar() == '\n') {

			//printf("%d*fact(%d)",i,i-1);
			fact*=i;

			sprintf(factInfo,"%d*fact(%d)",i,i-1);
			setcolor(3);
			outtextxy(j*50,15+j*20,factInfo);

			if(i<n){
				// Downward right arrow
				setcolor(7);
				line(j*50-20,5+j*20,j*50-20,18+j*20);
				line(j*50-20,18+j*20,j*50-5,18+j*20);
				line(j*50-10,15+j*20,j*50-5,18+j*20);
				line(j*50-10,21+j*20,j*50-5,18+j*20);
			}
			i--;
			j++;
		}

		// For reverse flow
		while(getchar() == '\n') {
			cleardevice();//Clear the diagram for new device

			j=2;
			for(i=n;i>l;i--){
				sprintf(factInfo,"%d*fact(%d)",i,i-1);
				setcolor(3);
				outtextxy((j-1)*50,15+(j-1)*20,factInfo);

				if(i<=n){
					// Downward right arrow
					setcolor(7);
					line(j*50-20,5+j*20,j*50-20,18+j*20);
					line(j*50-20,18+j*20,j*50-5,18+j*20);
					line(j*50-10,15+j*20,j*50-5,18+j*20);
					line(j*50-10,21+j*20,j*50-5,18+j*20);
				}
				j++;
			}

			sprintf(buff,"%d",l);
			strcpy(factInfo, buff);

                     strcat(factInfo,"*");
                     Pfact=1;
                     for(k=1;k<l;k++)
                     Pfact*=k;
                     sprintf(buff,"%ld",Pfact);
                     strcat(factInfo, buff);
                     l++;
			setcolor(3);
			outtextxy((j-1)*50,15+(j-1)*20,factInfo);
			if(l>n)
                     break;
              }
		if(getchar() == '\n') {
			cleardevice();
			setcolor(6);
			sprintf(factInfo,"Factorial of %d is %ld.",n,fact);
			outtextxy(20,20,factInfo);
		}
	}
	else if(n<0) {
		cleardevice();
		setcolor(6);
		outtextxy(20,20,"Please enter positive number only.");
	}
	else if(n==1 || n==0) {
		cleardevice();
		setcolor(6);
		sprintf(factInfo,"Factorial of %d is 1.",n);
		outtextxy(20,20,factInfo);
	}
	getch();
	closegraph();
	clrscr();
}

void singraph() {
	int gd=DETECT,gm;
	float x1,y1,x2,y2,midx,midy;
	char upperpick[10],lowerpick[10];
	int i,pick,pickTemp,pickSize;
	printf("Enter pick value\n");
	scanf("%d",&pick);

	pickTemp = pick;
	pickSize = 0;
	while(pickTemp!=0) {
		pickSize++;
		pickTemp/=10;
	}

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setcolor(6);
	setlinestyle(0,0,3);
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	// Right side portion
	for(i=0;i<midx;i++){
		x1=i+midx;
		y1=midy-100*sin(i*0.01745);
		x2=i+midx+1;
		y2=midy-100*sin((i+1)*0.01745);
		line(x1,y1,x2,y2);
	}
	// Left side portion
	for(i=midx;i>0;i--){
		x1=i;
		y1=midy-100*sin((i-midx)*0.01745);
		x2=i-1;
		y2=midy-100*sin((i-midx-1)*0.01745);
		line(x1,y1,x2,y2);
	}
	setlinestyle(0,0,1);
	setcolor(3);
	line(midx,10,midx,470);//y-axis
	line(0,midy,midx*2,midy);//x-axis
	setcolor(8);
	line(0,midy-101,midx*2,midy-101);//+ve max on y-axis
	line(0,midy+101,midx*2,midy+101);//-ve max on y-axis

	//Labaling on screen
	setcolor(7);
	outtextxy(0,0,"Sin wave");
	setcolor(8);
	sprintf(upperpick,"%d",pick);
	outtextxy(318-8*pickSize,130,upperpick);//Per character about 8 pixel
	outtextxy(308,231,"0");
	sprintf(lowerpick,"-%d",pick);
	outtextxy(310-8*pickSize,332,lowerpick);
	getch();
	closegraph();
	clrscr();
}

void cosgraph() {
	int gd=DETECT,gm;
	float x1,y1,x2,y2,midx,midy;
	char upperpick[10],lowerpick[10];
	int i,pick,pickTemp,pickSize;
	printf("Enter pick value\n");
	scanf("%d",&pick);

	pickTemp = pick;
	pickSize = 0;
	while(pickTemp!=0) {
		pickSize++;
		pickTemp/=10;
	}
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setcolor(6);
	setlinestyle(0,0,3);
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	// Right side portion
	for(i=0;i<midx;i++){
		x1=i+midx;
		y1=midy-100*cos(i*0.01745);
		x2=i+midx+1;
		y2=midy-100*cos((i+1)*0.01745);
		line(x1,y1,x2,y2);
	}
	// Left side portion
	for(i=midx;i>0;i--){
		x1=i;
		y1=midy-100*cos((i-midx)*0.01745);
		x2=i-1;
		y2=midy-100*cos((i-midx-1)*0.01745);
		line(x1,y1,x2,y2);
	}
	setlinestyle(0,0,1);
	setcolor(3);
	line(midx,10,midx,midy*2);//y-axis
	line(0,midy,midx*2,midy);//x-axis
	setcolor(8);
	line(0,midy-101,midx*2,midy-101);//+ve max on y-axis
	line(0,midy+101,midx*2,midy+101);//-ve max on y-axis
	setcolor(7);
	outtextxy(0,0,"Cos wave");
	setcolor(8);
	sprintf(upperpick,"%d",pick);
	outtextxy(318-8*pickSize,130,upperpick);
	outtextxy(308,231,"0");
	sprintf(lowerpick,"-%d",pick);
	outtextxy(310-8*pickSize,332,lowerpick);
	getch();
	closegraph();
	clrscr();
}

void pieChart(){
       int gd=DETECT,gm,x,y;
       double f,r,e,c,avg;
       int fh,rh,eh,ch;

       printf("\n\n\nEnter the value of food: ");
       scanf("%lf",&f);

       printf("\nEnter the value of rent: ");
       scanf("%lf",&r);

       printf("\nEnter the value of electricity: ");
       scanf("%lf",&e);

       printf("\nEnter the value of cloth: ");
       scanf("%lf",&c);

       avg=360/(f+r+e+c);
       fh=avg*f;
       rh=avg*r;
       eh=avg*e;
       ch=360-(fh + rh + eh);

       initgraph(&gd, &gm, "c:\\turboc3\\bgi");

       settextstyle(BOLD_FONT,HORIZ_DIR,2);
       outtextxy(220,10,"PIE CHART");
       /* Setting cordinate of center of circle */
       x = getmaxx()/2;
       y = getmaxy()/2;

       setfillstyle(SOLID_FILL, BLUE);
       pieslice(x, y, 0,fh, 120);

       setfillstyle(SOLID_FILL, RED);
       pieslice(x, y, fh , fh+rh , 120);

       setfillstyle(SOLID_FILL, BROWN);
       pieslice(x, y, fh+rh,fh+rh+eh, 120);

       setfillstyle(SOLID_FILL, MAGENTA);
       pieslice(x, y, fh+rh+eh,  fh+rh+eh+ch , 120);

       setfillstyle(SOLID_FILL, BLUE);
       bar(500,85,525,105);
       settextstyle(3,HORIZ_DIR,1);
       setcolor(BLUE);
       outtextxy(530,85,"FOOD");

       setfillstyle(SOLID_FILL, RED);
       bar(500,110,525,135);
       settextstyle(3,HORIZ_DIR,1);
       setcolor(RED);
       outtextxy(530,105,"RENT");

       setfillstyle(SOLID_FILL, BROWN);
       bar(500,140,525,165);
       settextstyle(3,HORIZ_DIR,1);
       setcolor(BROWN);
       outtextxy(530,135,"ELECTRICITY");

       setfillstyle(SOLID_FILL, MAGENTA);
       bar(500,170,525,195);
       settextstyle(3,HORIZ_DIR,1);
       setcolor(MAGENTA);
       outtextxy(530,165,"CLOTH");

    	getch();
       closegraph();
}

void barDiagram(){
       int gd=DETECT,gm,x,y;
       int fullMark,i=0,subMark[4],tempMark;
       char subName[4][10] = {
              "physics",
              "math",
              "computer",
              "electrical"
       };
       int colors[] = {4, 2, 1, 3};
       initgraph(&gd, &gm, "c:\\turboc3\\bgi");

       printf("\nEnter full mark of math\t:");
       scanf("%d",&fullMark);

       printf("\n\n\t\t INPUT DATA FOR MARK OF A STUDENT\n\n\n");

       while(1) {
              printf("\nEnter the mark of %s\t: ",subName[i]);
              scanf("%d",&tempMark);
              if((tempMark > fullMark) || (tempMark < 0) )
                     printf("Please enter mark between 0 and %d.",fullMark);
              else {
                     subMark[i] = tempMark;
                     i++;
                     if(i==4)
                            break;
              }
       }

       clrscr();

       outtextxy(10, 10 + 10, "Marks obtained by a student ");

	//initilizing lines for x and y axis
	setcolor(1);
	line(100,320,100,60);
	line(100,320,500,320);
	//creating bars with certain filling style

	for(i=0; i<4; i++) {
              // for bar generation
              setfillstyle(LINE_FILL,colors[i]);
              bar(150 + 75*i,320,200 + 75*i,320 - 4*subMark[i]*60/fullMark);

              // for symbol generation
              bar(500,85 + 30*i,525,105 + 30*i);
              settextstyle(3,HORIZ_DIR,1);
              setcolor(colors[i]);
              outtextxy(530,85 + 30*i,subName[i]);
	}
       getch ();
       closegraph();
}
