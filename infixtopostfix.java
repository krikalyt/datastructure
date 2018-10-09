package datastructurebyKrishna;

import java.util.Stack;

public class infixtopostfix {
    private String expression;
    private String result = "";
    public infixtopostfix(String expression){
        this.expression = expression;
    }



    public String getTheResult(){
        Stack<Character> stack = new Stack<Character>();
        stack.add('(');
        expression = expression + ')';
        int i=0;
        while(true){
            if(stack.empty()){
                break;
            }
            if(expression.charAt(i)=='('){
                stack.add('(');
            }
            else if(expression.charAt(i)==')'){
                while(true){
                    char rightpara = stack.pop();
                    if(rightpara=='('){
                        break;
                    }
                    result = result + rightpara;
                }
            }
            else{
                int isoperator = isoperator(expression.charAt(i));
                if(isoperator==-1){
                    result = result+expression.charAt(i);
                }
                else{
                    while(true){
                        char dothis = (stack.pop());
                        if(isoperator(dothis)>=isoperator){
                            result = result + dothis;
                        }
                        else{
                            stack.add(dothis);
                            stack.add(expression.charAt(i));
                            break;
                        }
                    }
                }
            }

            i++;
        }
        return result;
    }

    private int isoperator(char ch)
    {
        switch (ch)
        {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }
        return -1;
    }
}
