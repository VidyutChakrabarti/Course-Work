public abstract class TV{
   int channel; 
   boolean on_or_off;
   public void on(){
    this.on_or_off = true; 
   } 
   public void off(){
    this.on_or_off = false; 
   }
   public void tuneChannel(int channel){
    this.channel = channel;
   }
}