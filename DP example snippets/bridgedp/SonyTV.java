public class SonyTV extends TV{
   int channel; 
   boolean on_or_off;
   public void on(){
    this.on_or_off = true;
    System.out.println("Sonytv was switched on."); 
   } 
   public void off(){
    this.on_or_off = false;
    System.out.println("Sonytv was switched off."); 
   }
   public void tuneChannel(int channel){
    this.channel = channel;
    System.out.println("Sonytv was set."); 
   }
}