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
        for(int i = 0; i < n - 1; i++){
            array.add(i);
            int j = i - 1;
            while(j >= 0 && array.get(j) > i){
                array.set(j + 1, j);
                j--;
            }
            array.set(j + 1, i);
        }
    }
    public void mergeSort() {
        subMergeSort(0, array.size());
    }
    private void subMergeSort(int p, int r) {
        if(p < r - 1){
            int q = (p + r) / 2;
            subMergeSort(p, q);
            subMergeSort(q, r);
            fusion(p, q, r);
        }
    }
    private void fusion(int p, int q, int r){
        int n1 = q - p;
        int n2 = r - q;
        List<Integer> ag = new ArrayList<>(n1);
        List<Integer> ad = new ArrayList<>(n2);

        //Remplissage des tableaux
        for(int i = p; i < q; i++)
            ag.add(array.get(i));
        for(int i = q; i < r; i++)
            ad.add(array.get(i));

        int indg = 0;
        int indd = 0;
        int i = p;
        while(i < r){
            if(indg == n1){
                array.set(i, ad.get(indd));
                indd++;
            }
            else if(indd == n2){
                array.set(i, ag.get(indg));
                indg++;
            }
            else if(ag.get(indg) < ad.get(indd)){
                array.set(i, ag.get(indg));
                indg++;
            }
            else{
                array.set(i, ad.get(indd));
                indd++;
            }
            i++;
        }
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
