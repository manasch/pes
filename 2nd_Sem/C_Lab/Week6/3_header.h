typedef struct date{
    int dd,mm,yy;
}date_info;

void read(date_info *);
void display(date_info *);
int comp(date_info *, date_info *);