class Pair{
    int num;
    int ones;
    Pair(int num,int ones){
        this.num = num;
        this.ones = ones;
    }
}

class Solution {
    public int[] sortByBits(int[] arr) {
        List<Pair> list = new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            int num = arr[i];
            int count = 0;
            
            while(num > 0){
                if(num % 2 == 1){
                    count++;
                }
                num = num/2;
            }

            list.add(new Pair(arr[i],count));
        }

        list.sort((a,b)->{
            if(a.ones == b.ones)
                return a.num - b.num;
            return a.ones - b.ones;
        });

        int nums[] = new int[list.size()];

        for(int i=0;i<list.size();i++){
            nums[i] = list.get(i).num;
        }

        return nums;
    }
}