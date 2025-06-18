class Consumer extends Thread{
    Container c;
    Consumer(Container c){
        this.c=c;
    }
    public void run(){
        int n;
        while(true){
            synchronized(c){
                if(c.available==false){
                    try{
                        c.wait();
                    }catch(InterruptedException e){
                        System.out.println(e);
                    }
                }
                n=c.get();
                System.out.println("Got:\t"+n);
                c.available=false;
                try{
                    Thread.sleep(1000);
                }catch(InterruptedException e){
                    System.out.println(e);
                }
                c.notify();
            }
        }
    }
    
}