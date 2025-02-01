public class ConcreteRemote1 extends RemoteControl{
    private TV implementor; 
    public ConcreteRemote1(TV tv){
        this.implementor = tv; 
    }
    public void on(){
        implementor.on(); 
    }
    public void off(){
        implementor.off(); 
    }
    public void setChannel(int channel){
        implementor.tuneChannel(channel);
    }
}