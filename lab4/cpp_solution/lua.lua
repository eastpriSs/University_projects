function sort(array)
  local n = #array
  for i = 1, n - 1 do
    for j = i + 1, n do
      if array[i] > array[j] then
        array[i], array[j] = array[j], array[i]
      end
    end
  end
  return array
end