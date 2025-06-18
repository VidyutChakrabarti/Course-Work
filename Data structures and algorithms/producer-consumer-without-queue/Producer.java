class Producer extends Thread{
    Container c;
    Producer(Container c){
        this.c=c;
    }
    public void run(){
        int n=1;
        while(true){
            synchronized(c){
                if(c.available==true){
                    try{
                        c.wait();
                    }catch(InterruptedException e){
                        System.out.println(e);
                    }
                }
                c.put(n);
                System.out.println("Put:\t"+n);
                n++;
                c.available=true;
                c.notify();
            }
        }
    }
    
}