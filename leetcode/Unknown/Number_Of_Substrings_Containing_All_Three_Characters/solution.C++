count += n - (right + 1);
mp[s[left]]--;
if (mp[s[left]] == 0) {
mp.erase(s[left]);
count++;
}
left++;
return count;
};