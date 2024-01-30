public class Main {
    public static void main(String[] args) {
        // Vérification de la conformité des paramètres


        // Décision du nombre de valeurs
        int nbValues = 100;
        if(args.length == 2)
            nbValues = Integer.parseInt(args[1]);

        //Décision du tri à faire
        int tri = 0;
        if(args.length != 0){
            if(args[0].equals("--merge") || args[0].equals("-m"))
                tri = 1;
            else if(args[0].equals("--quick") || args[0].equals("-q"))
                tri = 2;
        }

        Sorter sorter = new Sorter(nbValues);

        if(tri == 0)
            sorter.insertSort(nbValues);
        else if(tri == 1) {
            sorter.randomFill(nbValues);
            sorter.mergeSort(0, sorter.getArray().size());
        }
        else {
            sorter.randomFill(nbValues);
            sorter.quickSort();
        }

        // Affichage du tableau
        sorter.displayArray();

        // Vérification de la conformité du tri
        if(!sorter.verifySort())
            System.out.println("Le tableau est mal trié");
    }
}