# i n c l u d e < s t a c k >  
 # i n c l u d e < i o s t r e a m >  
 # i n c l u d e < c m a t h >  
 # i n c l u d e < s t r i n g >  
 # i n c l u d e < c s t d i o >  
 # i n c l u d e < a l g o r i t h m >  
 # i n c l u d e < s s t r e a m >  
 # i n c l u d e < i o m a n i p >  
 # i n c l u d e   < c s t r i n g >  
 # i n c l u d e   < c s t d l i b >  
 # i n c l u d e   < v e c t o r >  
 # i n c l u d e   < m a p >  
 # i n c l u d e   < q u e u e >  
 # i n c l u d e   < s e t >  
  
 u s i n g   n a m e s p a c e   s t d ;  
  
 c o n s t   i n t   M A X   =   1 5 ; / / � � � � � � � � � � � � � � 1 2 � � � �  
  
 / / � � � � � � � � � � � � � � � � � � � � � � � � x � � y � �  
 s t r u c t   N o d e  
 {  
         d o u b l e   x ;  
         d o u b l e   y ;  
 } ;  
 N o d e   n d [ M A X ] ;  
  
 / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � c o l o r � � � � � � � � � � � � � � � � � � � � � � � � c o l o r   = =   0   � � � � � � � � � � � � � � � �  
 s t r u c t   G r a p h  
 {  
         i n t   e d g e s [ M A X ] [ M A X ] ;  
         i n t   c o l o r [ M A X ] ;  
 } G ;  
 / / � � � � � � � � � � � � � � � �  
 d o u b l e   d i s ( d o u b l e   x 1 ,   d o u b l e   y 1 ,   d o u b l e   x 2 ,   d o u b l e   y 2 )  
 {  
         r e t u r n   s q r t ( ( x 1   -   x 2 ) * ( x 1   -   x 2 )   +   ( y 1   -   y 2 ) * ( y 1   -   y 2 ) ) ;  
 }  
  
 / / � � � � � � � � � � 2 0 � � � � � � � � � � � � � �  
 v o i d   c o n n e c t ( i n t   i d )  
 {  
         f o r   ( i n t   i   =   1 ;   i   <   i d ;   i + + )  
         {  
                 d o u b l e   d i s t a n c e   =   d i s ( n d [ i d ] . x ,   n d [ i d ] . y ,   n d [ i ] . x ,   n d [ i ] . y ) ;  
                 i f   ( d i s t a n c e   < =   2 0 . 0 1 )  
                         G . e d g e s [ i d ] [ i ]   =   1 ,   G . e d g e s [ i ] [ i d ]   =   1 ;  
         }  
 }  
  
 / / � � � � � � � � � �  
 v o i d   i n i t i a l _ g r a p h ( )  
 {  
         m e m s e t ( G . c o l o r ,   0 ,   s i z e o f ( G . c o l o r ) ) ;  
         m e m s e t ( G . e d g e s ,   0 ,   s i z e o f ( G . e d g e s ) ) ;  
 }  
  
 / / � � � � � � � � � � � � � � � � � � � � � �  
 i n t   m i n _ c o l o r s ( i n t   n )  
 {  
         i n t   u s e d [ 1 0 ]   =   {   0   } ; / / u s e d [ i ]   = =   1   � � � � � � � � � � i � � � � � � � � � � � � � � � � � �  
         i n t   m a x _ c o l o r   =   0 ; / / � � � � � � � � � � � � � � � � � �  
         f o r   ( i n t   i   =   1 ;   i   < =   n ;   i + + )  
         {  
                 m e m s e t ( u s e d ,   0 ,   s i z e o f ( u s e d ) ) ;  
                 f o r   ( i n t   j   =   1 ;   j   < =   n ;   j + + )  
                 {  
                         i f   ( i   ! =   j   & &   G . e d g e s [ i ] [ j ] )   / / � � � � � � � �   j   � � � � � �   i   � � � � � � � � � � � � � � � � � � � � j � � � � � � � � � � � � u s e d  
                                 u s e d [ G . c o l o r [ j ] ]   =   1 ;  
                 }  
                 f o r   ( i n t   k   =   1 ;   k   < =   m a x _ c o l o r ;   k + + ) / / � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �   i   � � � � � � � � � � � � � � � � � � � � � �  
                 {  
                         i f   ( ! u s e d [ k ] )   / / � � � � � � � � � � � � � � i � � � � � � � � � � � � � �  
                         {  
                                 G . c o l o r [ i ]   =   k ;  
                                 b r e a k ;  
                         }  
                 }  
                 i f   ( ! G . c o l o r [ i ] ) / / � � � � � � � � � � � � � � � � � � � � � �   i   � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � � �  
                         m a x _ c o l o r   + =   1 ,   G . c o l o r [ i ]   =   m a x _ c o l o r ;  
         }  
         r e t u r n   m a x _ c o l o r ;  
 }  
  
 i n t   m a i n ( )  
 {  
         i n t   n ;  
         i n t   n u m   =   1 ;  
         w h i l e   ( c i n   > >   n ,   n )  
         {  
                 i n i t i a l _ g r a p h ( ) ;  
                 m e m s e t ( n d ,   0 ,   s i z e o f ( n d ) ) ;  
                 f o r   ( i n t   i   =   1 ;   i   <   n   +   1 ;   i + + )  
                 {  
                         c i n   > >   n d [ i ] . x   > >   n d [ i ] . y ;  
                         c o n n e c t ( i ) ;  
                 }  
                 i n t   m i n _ c   =   m i n _ c o l o r s ( n ) ;  
                 c o u t   < <   " T h e   t o w e r s   i n   c a s e   "   < <   n u m + +   < <   "   c a n   b e   c o v e r e d   i n   " < <   m i n _ c   < < "   f r e q u e n c i e s . "   < <   e n d l ;  
  
         }  
  
 }  
  
 