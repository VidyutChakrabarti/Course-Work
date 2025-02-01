public class Main{
    public static void main(String args[]){
        ConcreteRemote1 remoteControl = new ConcreteRemote1(new SonyTV());
        remoteControl.on();
        remoteControl.off(); 
        remoteControl.setChannel(2);
    }
}


                                            
