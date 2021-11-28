#include <iostream>
#include <fstream>


using namespace std;


struct Line{
   
   char* name;
   int cost = 0;
   int count = 0;
};

struct Table{
   
   int size = 0;
   Line* line = 0;
};


int print (Table &table){
   cout << "№\tname\tcost\tcount\n";
   for(int i = 0; i < table.size; i++){
      Line& l = table.line[i];
      printf("%d\t%s\t%d\t%d\n", i + 1, l.name, l.cost, l.count);
   }
   cout << endl;
}

void copy (Line &to, Line &from){
   
   to.name = from.name;
   to.cost = from.cost;
   to.count = from.count;
}

void swap (Line &line1, Line &line2){
   
   Line temp;
   copy(temp, line1);
   copy(line1, line2);
   copy(line2, temp);
}

void ShellSort(Table &table){
   int length = table.size;
   int d = length / 2;
   
   while (d > 0){
      for (int i = 0; i < length - d; i++){
         int j = i;
         
         while (j >= 0 && table.line[j].cost > table.line[j+d].cost){
            swap(table.line[j + d], table.line[j]);
            j -= d;
         }
      }
      d /= 2;
   }
}



bool readFile(Table& table, const char* name){
   
   ifstream inFile(name);
   
   if(inFile.is_open()){
      
      int size;
      inFile >> size;
      table.size = size;
      table.line = new Line[size];
      
      for(int i = 0; i < size; i++){
         table.line[i].name = new char[8];
         inFile >> table.line[i].name;
         inFile >> table.line[i].cost;
         inFile >> table.line[i].count;
      }
      
      return true;
   } else {
      return false;
   }
}

int main(){
   
   Table table;
   
   if(readFile(table, "goods.txt")){
      ShellSort(table); 
      print(table);
      return 0;
   } else {
      cout << "error: No iner file!\n";
      return 1;
   }
   
}
