/*
 * @lc app=leetcode id=22 lang=rust
 *
 * [22] Generate Parentheses
 */

// @lc code=start
struct Solution {}
impl Solution {
    pub fn back_track(r: i32, remain: i32, mut pattern: String, result: &Vec<String>) {
        if r == 0 {
            if remain > 0 {
                for i in 0..remain {
                    pattern.push_str(")");
                }
            }
            result.push(pattern);
        }
        pattern.push_str("(");
        Self::back_track(r - 1, remain + 1, pattern, result);
        pattern.push_str(")");
        Self::back_track(r - 1, remain, pattern, result);
    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result: Vec<String> = Vec::new();
        let mut pattern: String = "".to_string();
        Self::back_track(n, 0, pattern, &result);
        return result;
    }
}
// @lc code=end
fn main() {
    let r: Vec<String> = Solution::generate_parenthesis(2);
    for ss in r {
        println!("{}", ss);
    }
}
