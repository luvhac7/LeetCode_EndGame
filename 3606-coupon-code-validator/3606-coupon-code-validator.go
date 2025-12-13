import "sort"

func validateCoupons(code []string, businessLine []string, isActive []bool) []string {
    e, g, p, r := []string{}, []string{}, []string{}, []string{}

    for i := range isActive {
        if !isActive[i] {
            continue
        }

        bl := businessLine[i]
        if bl != "electronics" && bl != "grocery" &&
           bl != "pharmacy" && bl != "restaurant" {
            continue
        }

        if len(code[i]) == 0 {
            continue
        }

        ok := true
        for _, ch := range code[i] {
            if !(ch >= 'a' && ch <= 'z' ||
                 ch >= 'A' && ch <= 'Z' ||
                 ch >= '0' && ch <= '9' || ch == '_') {
                ok = false; break
            }
        }
        if !ok {
            continue
        }

        switch bl[0] {
        case 'e': e = append(e, code[i])
        case 'g': g = append(g, code[i])
        case 'p': p = append(p, code[i])
        case 'r': r = append(r, code[i])
        }
    }

    sort.Strings(e); sort.Strings(g)
    sort.Strings(p); sort.Strings(r)
    return append(append(append(e, g...), p...), r...)
}