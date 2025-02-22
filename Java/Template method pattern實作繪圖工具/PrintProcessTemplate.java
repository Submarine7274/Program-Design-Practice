public abstract  class PrintProcessTemplate {
    int number;
    int times;
    abstract void printHeader();
    abstract void printBody();
    abstract void printFooter();
    final void print(int times){
        this.times =times;
        this.number = times+1;
        for(int i =1; i<=times; i++){
            printHeader();
            printBody();
            printFooter();
            System.out.println("");
        }
    }
}