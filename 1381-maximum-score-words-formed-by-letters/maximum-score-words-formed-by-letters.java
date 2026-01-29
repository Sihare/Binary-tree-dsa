class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        
        // Creating the frequency array for letters 
        int freq[] = new int[26] ;
        for( char ch : letters ){
            // char -> index 
            freq[ch - 'a']++ ;
        }

        return fun( words , freq , score , 0 , "" ) ;

    }

    public int fun(String[] words , int freq[] , int score[] , int pos , String subsets ) {

        // Base case 
        if( pos >= words.length ){
        //    System.out.println(subsets) ;
            return 0;
      }
        // exclude the words[pos] -> What is the score of subset => exclude value 
                int exclude = 0 + fun( words , freq , score , pos+1 , subsets+" , x , ") ;

        // include the words[pos] -> What is the score of subset => include value 
        int wordScore = 0 ;
        boolean isPossible = true ;
        int include = 0 ;
        String word = words[pos] ; // dog 
        
        for( int i = 0 ; i < word.length() ; i++ ){
            // And check if it is feasible to create the word dog with 
            char ch = word.charAt(i) ;

            // given frequency of character 
            freq[ ch - 'a']-- ;

            wordScore += score[ch-'a'] ;

            if( freq[ch-'a'] < 0 ){
                // Then it is not possible to create the word 
                isPossible = false ;
            }
        }

        if( isPossible ){
         //   System.out.println( "word = " +word+"  , score = "+ wordScore) ;
                include = wordScore + fun( words , freq , score , pos+1 , subsets+" , "+word) ;
                
        }
     
            // If isPossible is false then bring back the prev state of freq array          
            for( int i = 0 ; i < word.length() ; i++ ){

                char ch = word.charAt(i);

                freq[ch-'a']++ ;
            }


        




        
        return Math.max( include , exclude ) ;

    }
}