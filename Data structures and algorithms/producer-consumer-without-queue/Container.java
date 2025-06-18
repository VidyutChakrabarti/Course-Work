class Container{
   int item;
   boolean available;
   Container(){
       available=false;
   }
   void put(int item){
       this.item=item;
   }
   int get(){
       return item;
   } 
}