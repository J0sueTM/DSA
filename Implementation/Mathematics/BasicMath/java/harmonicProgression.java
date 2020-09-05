import java.util.*;

public class harmonicProgression
{
    static boolean isHP(double arr[])
    {
        if (arr.length == 1)
            return true;

        ArrayList<Integer> rec = new ArrayList<Integer>();
        for (int i = 0; i < arr.length; ++i)
            rec.add((int)(1 / arr[i]));
        Collections.sort(rec);
        int d = (int)rec.get(1) - (int)rec.get(0);
        for (int i = 2; i < arr.length; ++i)
            if (rec.get(i) - rec.get(i - 1) != d)
                return false;

        return true;
    }

    public static void main(String[] args)
    {
        double arr[] = {1 / 5, 1 / 10, 1 / 15, 1 / 20, 1 / 25};
        
        if (isHP(arr))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
