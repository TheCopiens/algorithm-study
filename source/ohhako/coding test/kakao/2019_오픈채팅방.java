import java.util.HashMap;
class Solution {
    public String[] solution(String[] record) {
        HashMap<String,String> users = new HashMap<>();
        int sizeOfManagerMessage = 0;
        for(int i=0 ; i<record.length;i++ ){
            String[] msg = record[i].split(" ");
            if(msg[0].equals("Enter")){
                users.put(msg[1],msg[2]);
                sizeOfManagerMessage++;
            }else if(msg[0].equals("Change")){
                users.put(msg[1],msg[2]);
            }else if(msg[0].equals("Leave"))
                sizeOfManagerMessage++;
        }

        String[] messageOfManager = new String[sizeOfManagerMessage];
        int j=0;
        for(int i=0 ; i<record.length;i++ ){
            String[] msg = record[i].split(" ");
            StringBuffer new_msg = new StringBuffer();
            if(msg[0].equals("Enter")){
                new_msg.append(users.get(msg[1]));
                new_msg.append("님이 들어왔습니다.");
                messageOfManager[j++] = new_msg.toString();
            }else if(msg[0].equals("Leave")){
                new_msg.append(users.get(msg[1]));
                new_msg.append("님이 나갔습니다.");
                messageOfManager[j++] = new_msg.toString();
            }
        }

        return messageOfManager;
    }
}