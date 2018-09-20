for i = 1:100
    mkdir(num2str(i));
    for j = 0:5
        mkdir([num2str(i),'\',num2str(j)]);
    end
    for k = 0:99
        seq = randi([-1000,1000],1,i);
        for j = 0:5
            mkdir([num2str(i),'\',num2str(j),'\',num2str(k)]);
            fout = fopen([num2str(i),'\',num2str(j),'\',num2str(k),'\test.in'],"w+");
            fprintf(fout,"%d\n%d\n",j,i);
            for l=1:i
                fprintf(fout,"%d\n",seq(l));
            end
            fclose(fout);
        end
    end
end