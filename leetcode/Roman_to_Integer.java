class Solution {
    public static int get(char s) {
        String[] symbolarray = {"I", "V", "X", "L", "C", "D", "M"};
        int[] value = {1, 5, 10, 50, 100, 500, 1000};
        int loc = 0;
        for (String symbol : symbolarray) {
            if (symbol.equals(Character.toString(s))) {
                return value[loc];
            } else {
                loc++;
            }
        }
        return -1;
    }

    public int romanToInt(String s) {
        char[] s1 = s.toCharArray();
        int sum = get(s1[0]);
        for(int i=1; i < s1.length; i++){
            if(get(s1[i-1]) == get(s1[i])){
                sum += get(s1[i]);
            }
            else if(get(s1[i-1]) > get(s1[i])){
                sum += get(s1[i]);
            }
            else if(get(s1[i-1]) < get(s1[i])){
                sum -= get(s1[i-1]);
                sum += (get(s1[i])-get(s1[i-1]));
            }
        }
        return sum;
    }
}
