import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Sorter {
    private List<Integer> array;
    public Sorter(int arraySize){
        this.array = new ArrayList<>(arraySize);
    }
    public void randomFill(int n){
        Random rand = new Random();

        // Remplissage du tableau
        for(int i = 0; i < n; i++)
            this.array.add(rand.nextInt(100));
    }
    public void displayArray(){
        // Vérification de la présence de valeurs
        if(array.isEmpty()){
            System.out.println("Le tableau est vide");
            return;
        }

        for(int i = 0 ; i < this.array.size(); i++) {
            if(i % 10 == 0) {
                if(i != 0)
                    System.out.println("|");
                System.out.print("[" + i + "] : ");
            }
            System.out.print("| " + array.get(i) + " ");
        }
        System.out.println("|");
    }
    public boolean verifySort(){
        boolean isSorted = true;
        int i = 1;
        while(isSorted && i < array.size()){
            if(array.get(i - 1) > array.get(i))
                isSorted = false;
            i++;
        }
        return isSorted;
    }
    public void insertSort(int n){
        array.add(0);
        for(int i = 0; i < n; i++){
            array.add(i);
            int j = i - 1;
            while(j >= 0 && array.get(j) > i){
                array.set(j + 1, j);
                j--;
            }
            array.set(j + 1, i);
        }
    }
    public void mergeSort(int p, int q) {

    }
    public void subMergeSort(int p, int q, int r) {

    }
    public void quickSort(){

    }
    public void subQuickSort(int p, int r){

    }
    public int partition(int p, int r){
        return 0;
    }
    public List<Integer> getArray(){
        return this.array;
    }
    public void setArray(List<Integer> array){
        this.array = array;
    }
}
