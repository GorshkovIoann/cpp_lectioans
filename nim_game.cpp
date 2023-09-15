#include "std_lib_facilities.h"
//#include <unistd.h>
int p[9]={3,4,5,0,0,0,0,0,0};
int pp[9]={3,4,5,0,0,0,0,0,0};
int comp();
int summ(int p[]);
void comp_tern();
void you_tern();
void game();
int menu();
int settings();
int who_win=-1;
int summ(int p[]){
    int sm=0;
    for(int i=0;i<9;i++){
        sm+=p[i];
    }
    return sm;
}

int comp(){
    who_win=p[0]^p[1]^p[2]^p[3]^p[4]^p[5]^p[6]^p[7]^p[8];
    if (who_win==0){
        for(int i=0;i<10;++i){
        if (p[i]>0){
            p[i]-=1;
            cout<<"Reduces the number of items in a row  "<<i+1<<" by "<<1<<endl;
            return 0;
            
        }


    }
    }
    int how_win=-1;
    for(int i=0;i<10;++i){
        if (p[i]>0){
            for(int x=1;x<=p[i];++x){
                p[i]-=x;
                how_win=p[0]^p[1]^p[2]^p[3]^p[4]^p[5]^p[6]^p[7]^p[8];
                
                if( how_win==0){
                    cout<<"Reduces the number of items in a row  "<<i+1<<" by "<<x<<endl;
                    return 0;



                }
                p[i]+=x;
                
            }

        }
    }
return 0;
}
void comp_tern(){
    cout<<"Enemy's tern"<<endl;
    comp();
    
    if(summ(p)==0){
        cout<<"Your oponent win\n If you want to play more, enter 1, if you want to get to the menu, enter 2"<<endl;
        for(int i=0;i<10;++i){
            p[i]=pp[i];
        }
        int a=0;
        cin>>a;
        if ( a==1){
            game();
        }
        if (a==2){
            menu();
        }
        else{
            cout<<"I'm sorry, you've entered something that is not in the correct format. We're redirecting you to the menu"<<endl;
            menu();
            
        }
    }
    you_tern();



}
void you_tern(){
    cout<<"Your tern"<<endl;
    for(int i=0;i<9;++i){
        if (p[i]>0)
        cout<<"The number of items in the  "<<i+1<<" row = "<<p[i]<<endl;
    }
    cout<<"To remove items from a row, lead through first the row number, then the number of items you want to remove from the row"<<endl;
    int a,b;
    cin>>a>>b;
    if(p[a-1]-b>=0  && a>0 && a<10 ){
        p[a-1]-=b;
        
        
    
        if(summ(p)==0){
            cout<<"You win\n If you want to play more, enter 1, if you want to get to the menu, enter 2"<<endl;
            for(int i=0;i<10;++i){
            p[i]=pp[i];
        }
            int a=0;
            cin>>a;
            if ( a==1){
                game();
            }
            if (a==2){
                menu();
            }
            else{
                cout<<"I'm sorry, you've entered something that is not in the correct format. We're redirecting you to the menu"<<endl;
                menu();
            
        }
        
    }
    comp_tern();

    }
    else{
        cout<<"I'm sorry, you entered something that is not in the correct format. Try again."<<endl;
        you_tern();

    }


}
void game(){
    for(int i=0;i<9;++i){
        if (p[i]>0)
        cout<<"The initial number of items in the "<<i+1<<" row = "<<p[i]<<endl;
    }
    srand(time(0));
    int who1=rand()%2+1;
    string start="Lets start";
    cout<<start<<endl;
    if( who1==1){
        you_tern();
    }
    if (who1==2){
        comp_tern();
    }
}
int menu(){
    string main_menu = "        Hello, player\n You are welcome to the game NIM\nYou should to be ready: your opponent really strong\n For start game print 1 + enter\n For options print 2 + enter\n For exit print 3 + enter\n";
    cout<<main_menu;
    int numr;
    cin>> numr;
    if (numr==3){
        exit(0);
    }
    if(numr==2){
        settings();
    }
    if(numr==1){
        game();
    }
    cout<<"I'm sorry, you entered something that is not in the correct format. Try again."<<endl;
    menu();
    
    
  return 0;  
}
int settings(){
    int a,b;
    a=b=0;
    cout<<"You can customize the number of items in each row.\n To do this, first enter the row number, then the number of items you want to see in that row\n If you want to exit the menu, enter 0 enter 0 enter."<<endl;

    for(int i=0;i<9;++i){
        cout<<"Number of items in the "<<i+1<<" row = "<<p[i]<<"\n";
    }
    cin>>a>>b;
    if ((a==0)&&(b==0)){
        menu();
    }
    if (summ(p)==0){
        cout<<"No....";
        settings();
    }
    if(a>0 && a<10 && b>-1){
        p[a-1]=b;
        pp[a-1]=b;
        settings();
    }

    
    else{
        cout<<"I'm sorry, you entered something that is not in the correct format. Try again."<<endl;
        settings();

    }
return 0;
}


int main()
{
    
    
    menu();
    

    return 0;
}
