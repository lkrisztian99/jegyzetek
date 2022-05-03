#include "std_lib_facilities.h"


template<typename Iterator, typename Out,typename Pred>
Out MyCopy(Iterator f1,Iterator last,Out f2,Pred pred){
    while(f1!=last){
        if(pred(*f1)){
            *f2=*f1;
            f2++;
        }
        
        f1++;
        
    }

    return f2;
}


int main(){

    //tömbök definiálása
    array <int,10> MyArray={0,1,2,3,4,5,6,7,8,9};
    vector <int> MyVector={0,1,2,3,4,5,6,7,8,9};
    list <int> MyList={0,1,2,3,4,5,6,7,8,9};

    vector<int> EvenVector(10);
    list<int> EvenList(10);
    array <int,10> MyArray2;    //definiálunk egy második array listát         
    for(int i=0;i<10;i++){              //végigmegyek az első array listámon
        MyArray2[i]=MyArray[i]+2;       //második listám i-ik elemét egyenlővé teszem eredeti lista értéke+2-vel
    }

    vector<int> MyVector2=MyVector;        //létrehoztam egy új vektort amit egyből egyenlővé tettem az eredetim értékeivel
    for(int i=0; i<MyVector2.size();i++){
        MyVector2[i]=MyVector2[i]+3;        //megnöveltem az értékeit +3-al
    }

    list<int> MyList2 =MyList;
    for(auto &i :MyList2){
        i=i+5;
    }
    /*
    for(int i=0; i<10; i++){
        cout << "Array :"<< MyArray[i] << " Vector: "<< MyVector[i] << endl;
    }
 for(int i=0; i<10; i++){
        cout << "Array2 :"<< MyArray2[i] << " Vector2: "<< MyVector2[i] << endl;
    }
cout << "---------------"<< endl;*/
    //MyCopy(MyArray.begin(),MyArray.end(),MyVector2.begin());
    //MyCopy(MyList.begin(),MyList.end(),MyArray2.begin());
    MyCopy(MyArray.begin(),MyArray.end(),EvenVector.begin(),[](int x) -> bool {return (x%2)==0;});
    MyCopy(MyList.begin(),MyList.end(),EvenList.begin(),[](int x) -> bool {return (x%2)==0;});

    auto position = find(MyVector2.begin(),MyVector2.end(),3);
    if(position==MyVector2.end()){
        cout << "Nem található ilyen."<< endl;
    }
    else{
        for(int i=0;i<MyVector2.size(); i++){
            if(MyVector2[i]==*position){
                cout<< "Ebben a pozícióban található : "<< i << endl;
            }            
        }
    }
    cout <<" -----"  << endl;
    auto position2 = find(MyList2.begin(),MyList2.end(),27);
    if(position2==MyList2.end()){
        cout << "Nem található ilyen."<< endl;
    }
    else{
        for(auto const& i:MyList2){
            if(i==*position2){
                cout<< "Ebben a pozícióban található : "<< i << endl;
            }            
        }
    }


        cout << "Array érték nőtt 2-vel"<< endl;
    for(int i=0; i<10; i++){
        cout << "Array :"<< MyArray[i] <<  " Array2 :"<< MyArray2[i]<< endl;
    }
    cout << "Vektor érték nőtt 3-al"<< endl;
    for(int i=0; i<10; i++){
        cout <<  "Vector: "<< MyVector[i]<< " Vector2: "<< MyVector2[i] << endl;
    }
    cout <<"List érték nőtt 5-el" <<endl;
    for(auto const& i:MyList){
        cout<<"Lista: " << i << endl;
    }

    for(auto const& i:MyList2){
        cout<<"Lista2: " << i << endl;
    }


    cout << "--------Páros számos másolás: ----------" << endl;
    cout <<"Eredeti vector"<< endl;
    for(int i=0; i < MyVector.size(); i++){
        cout << MyVector[i] << endl;
    }

    cout << "Csak páros számok vector "<< endl;
    for(int i=0; i<EvenVector.size();i++){
        cout << EvenVector[i] << endl;
    }



    for(auto const& i:EvenList){
        cout<<"Páros számok: " << i << endl;
    }





}

