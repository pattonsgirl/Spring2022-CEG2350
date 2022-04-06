class Main {
    public static void main(String args[]) {
        System.out.println("This is output from main, calling function in another class now..");

        // printMe();
        
        funClass hiFriend = new funClass();
        hiFriend.printIn();
    }

    // I dont know if you need this but I added it

    // public static void printMe() {
    //     System.out.println("from Method in Main");
    // }
}
