import java.util.*;
class Solution {
  public String[] solution(String[] files) {
      
      Node[] nodes = new Node[files.length];
      for(int i=0 ; i<files.length ; i++){
           String file = files[i].toLowerCase();
           int start=0;
           int fin=0;
           char ch=' ';
           for(int j=0 ; j<file.length() ; j++){
               ch = file.charAt(j);
               if(ch=='0' || ch=='1' || ch=='2'|| ch=='3'|| ch=='4'
                 || ch=='5'|| ch=='6'|| ch=='7'|| ch=='8'|| ch=='9'){
                   start = j;
                   break;
               }
           }
           
           for(int j=start ; j<file.length() ; j++){
               ch = file.charAt(j);
               if(ch=='0' || ch=='1' || ch=='2'|| ch=='3'|| ch=='4'
                 || ch=='5'|| ch=='6'|| ch=='7'|| ch=='8'|| ch=='9'){
                   fin= j;
               }
               if(fin!=j)
                   break;
           }
          String head = file.substring(0,start);
          int number = Integer.parseInt(file.substring(start,fin+1));
          String tail = file.substring(fin+1,file.length());
          nodes[i] = new Node(files[i],head,number,tail);
      }
      Arrays.sort(nodes, new Comparator<Node>(){
          @Override
          public int compare(Node n1, Node n2){
              if(n1.head.equals(n2.head))
                  return Integer.compare(n1.number,n2.number);
              return (n1.head).compareTo(n2.head);
          }
      });
      
      String[] answer = new String[nodes.length];
      for(int i=0 ; i<nodes.length ; i++)
          answer[i] = nodes[i].letter;
          
      return answer;
  }
}

class Node{
    String letter;
    String head;
    int number;
    String tail;
    Node(String letter,String head,int number,String tail){
        this.letter = letter;
        this.head=head;
        this.number=number;
        this.tail=tail;
    }
}