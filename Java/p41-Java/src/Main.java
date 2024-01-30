public class Main {
    public static void main(String[] args) {
        // Decision of the number of values for the array
        int nbValues = 100;
        if(args.length == 2)
            nbValues = Integer.parseInt(args[1]);

        // Decision on the sort to execute
        int tri = 0;
        if(args.length != 0){
            if(args[0].equals("--merge") || args[0].equals("-m"))
                tri = 1;
            else if(args[0].equals("--quick") || args[0].equals("-q"))
                tri = 2;
        }

        // Instanciation and initialisation of a Sorter
        Sorter sorter = new Sorter(nbValues);
        if(tri != 0)
            sorter.randomFill(nbValues);

        // Start of the chronometer
        long start = System.nanoTime();

        // Choice on the sort to execute
        if(tri == 0)
            sorter.insertSort(nbValues);
        else if(tri == 1)
            sorter.mergeSort();
        else
            sorter.quickSort();

        // End of the chronometer
        long end = System.nanoTime();
        // Process of the time elapsed
        long timeElapsed = end - start;

        // Display of the sorted array
        sorter.displayArray();

        // Display of the time spent on the sorting
        System.out.println("Le tri a duré " + timeElapsed + " nanosecondes.");

        // Verification of the sorting of the array
        if(!sorter.verifySort())
            System.out.println("Le tableau est mal trié");
    }
}
