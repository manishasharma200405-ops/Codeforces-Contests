import java.util.* ;
 
public class SpongebobAndJoke {
    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in ) ;
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ;
         
        int[] b = new int[ m ] ;
        int[] ind = new int[n + 1] ;
        int[] ans = new int[ m ] ;
 
        for( int i = 1 ; i <= n ; i++ ){
            int x = sc.nextInt()  ;
            if( ind[ x ] == 0 ){
                ind[ x ] = i ; 
            }
            else {
                ind[ x ] = -1 ;
            }
        }
 
        for( int i = 0 ; i < m ; i++ ){
            b[ i ] = sc.nextInt() ; 
        }
 
        for ( int i = 0 ; i < m ; i++  ){
 
            if( ind[ b[i] ] == 0 ){
                System.out.println("Impossible") ;
                return ;
            }
            else if ( ind[ b[i] ] == -1 ){
                System.out.println("Ambiguity");
                return ;
            }
            else ans[i] = ind[ b[i] ] ;
        }
 
        System.out.println("Possible");
        for ( int i = 0 ; i < m ; i++ ){
            System.out.print( ans[i] + " " ) ;
        }
 
    }
}