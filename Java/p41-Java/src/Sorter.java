import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public interface Sorter {
    static void randomFill(List<Integer> a, int n, int maxVal){
        Random rand = new Random();
        for(int i = 0; i < n; i++)
            a.add(rand.nextInt(maxVal));
    }
    static void displayArray(List<Integer> a){
        // Verification of the existence of a single value
        if(a.isEmpty()){
            System.out.println("Le tableau est vide");
            return;
        }

        for(int i = 0 ; i < a.size(); i++) {
            if(i % 10 == 0) {
                if(i != 0)
                    System.out.println("|");
                System.out.print("[" + i + "] : ");
            }
            System.out.print("| " + a.get(i) + " ");
        }
        System.out.println("|");
    }
    static boolean verifySort(List<Integer> a){
        boolean isSorted = true;
        int i = 1;
        while(isSorted && i < a.size()){
            if(a.get(i - 1) > a.get(i))
                isSorted = false;
            i++;
        }
        return isSorted;
    }
    static void insertSort(List<Integer> a, int n){
        for(int i = 0; i < n ; i++){
            int cle = a.get(i);
            int j = i - 1;
            while(j >= 0 && a.get(j) > cle){
                a.set(j + 1, j);
                j--;
            }
            a.set(j + 1, cle);
        }
    }
    static void mergeSort(List<Integer> a) {
        subMergeSort(a, 0, a.size());
    }
    private static  void subMergeSort(List<Integer> a, int p, int r) {
        if(p < r - 1){
            int q = (p + r) / 2;
            subMergeSort(a, p, q);
            subMergeSort(a, q, r);
            fusion(a, p, q, r);
        }
    }
    private static  void fusion(List<Integer> a, int p, int q, int r){
        int n1 = q - p;
        int n2 = r - q;
        List<Integer> ag = new ArrayList<>(n1);
        List<Integer> ad = new ArrayList<>(n2);

        // Array filling
        for(int i = p; i < q; i++)
            ag.add(a.get(i));
        for(int i = q; i < r; i++)
            ad.add(a.get(i));

        int indg = 0;
        int indd = 0;
        int i = p;
        while(i < r){
            if(indg == n1){
                a.set(i, ad.get(indd));
                indd++;
            }
            else if(indd == n2){
                a.set(i, ag.get(indg));
                indg++;
            }
            else if(ag.get(indg) < ad.get(indd)){
                a.set(i, ag.get(indg));
                indg++;
            }
            else{
                a.set(i, ad.get(indd));
                indd++;
            }
            i++;
        }
    }
    static void quickSort(List<Integer> a, int n ){
        subQuickSort(a, 0,n);

    }
    static void subQuickSort(List<Integer> a, int p, int r){
        if(p < r - 1){
            int q = partition(a, p, r);
            subQuickSort(a, p, q);
            subQuickSort(a,q + 1, r);
        }
    }
    static int partition(List<Integer> a, int p, int r){
        int pivot = a.get(r - 1);
        int i = p;
        for(int j = p; j < r - 1; j++){
            if(a.get(j) <= pivot){
                int v = a.get(i);
                a.set(i, a.get(j));
                a.set(j, v);
                i++;
            }
        }
        int v = a.get(i);
        a.set(i, a.get(r - 1));
        a.set(r - 1, v);

        return i;
    }
}
