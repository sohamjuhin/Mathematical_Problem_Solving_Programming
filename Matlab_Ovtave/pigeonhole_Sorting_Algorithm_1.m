function pigeonhole_sort(arr)
% Find minimum and maximum values in arr
min_num = min(arr);
max_num = max(arr);
range = max_num - min_num + 1; % Find range

% Create an array of vectors. Size of array
% range. Each vector represents a hole that
% is going to contain matching elements.
holes = cell(1, range);

% Traverse through input array and put every
% element in its respective hole
for i = 1:length(arr)
    num = arr(i);
    holes{num - min_num + 1} = [holes{num - min_num + 1}, num];
end

% Traverse through all holes one by one. For
% every hole, take its elements and put in
% array.
index = 1; % index in sorted array
for i = 1:range
    for j = 1:length(holes{i})
        arr(index) = holes{i}(j);
        index = index + 1;
    end
end

disp("Sorted order is: ");
disp(arr);

end
