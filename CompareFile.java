import java.util.ArrayList;
import java.util.List;
import java.io.*; 

    public class CompareFile {
        public CompareFile(){
            System.out.println("CompareFile.CompareFile()");
        }

        public static void main(String[] args) throws Exception {
	    PrintWriter pw = new PrintWriter("File3.txt");
            BufferedReader br1 = null;
            BufferedReader br2 = null;
            String sCurrentLine;
            List<String> list1 = new ArrayList<String>();
            List<String> list2 = new ArrayList<String>();
            br1 = new BufferedReader(new FileReader("File1.txt"));
            br2 = new BufferedReader(new FileReader("File2.txt"));

            while ((sCurrentLine = br1.readLine()) != null) {
                list1.add(sCurrentLine);
            }
            while ((sCurrentLine = br2.readLine()) != null) {
                list2.add(sCurrentLine);
            }
            List<String> tmpList = new ArrayList<String>(list1);
            tmpList.removeAll(list2);
            System.out.println("content from File1.txt which is not there in File2.txt");
            for(int i=0;i<tmpList.size();i++){
                System.out.println(tmpList.get(i));
                pw.println(tmpList.get(i));
            }

            System.out.println("content from File2.txt which is not there in File1.txt");
	    tmpList = list2;
            tmpList.removeAll(list1);
            for(int i=0;i<tmpList.size();i++){
                System.out.println(tmpList.get(i));
		pw.println(tmpList.get(i));
            }
    System.out.println("Written into File3.txt");
    pw.close();    
    }
    }
