class Solution {
    public int maxCoins(int[] nums) {
        ArrayList<Integer> num = new ArrayList<>();
        for(int i=0; i<nums.length; i++){
            num.add(nums[i]);
        }
        int sum = 0;
        while(num.size() != 0){
            int index = 1;
            if(num.size() > 3){
                int cal = num.get(index-1) * num.get(index+1);
                for(int i=2; i<num.size()-1; i++){
                    if((num.get(i-1) * num.get(i+1)) > cal){
                        cal = num.get(i-1) * num.get(i+1);
                        index = i;
                    }
                }
            }

            if(num.size() == 3){
                index = num.size() / 3;
            }
            else if(num.size() == 2){
                if(num.get(0) < num.get(1)){
                    index = 0;
                }
                else{
                    index = 1;
                }
            }
            else if(num.size() == 1){
                index = 0;
            }

            System.out.println(index);
            int left, right = 1;
            if(index == 0){
                left = 1;
                if(num.size() == 1){
                    right = 1;
                }
                else{
                    right = num.get(index + 1);
                }
            }

            else if((num.size() == 2) && index == 1){
                left = num.get(index-1);
                right = 1;
            }

            else{
                left = num.get(index-1);
                right = num.get(index+1);
            }

            sum += (left * num.get(index) * right);
            num.remove(index);
        }
        return sum;
    }
}